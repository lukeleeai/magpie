from langchain_openai import ChatOpenAI
from langchain_mistralai import ChatMistralAI
from langchain.prompts import ChatPromptTemplate
import os
import re
import textwrap
import time
import re
from typing import List, Dict
import difflib



class LLMBase:
    def __init__(self):
        self.id = 0
        self._llm = None
        self.is_debugging = False

    @property
    def llm(self):
        # Lazy load the LLM to avoid deepcopy/pickle errors with thread locks
        if self._llm is None:
            # Ues Mistral
            # self._llm = ChatMistralAI(
            #     model="codestral-latest",
            #     temperature=0.7,
            #     mistralai_api_key=os.getenv("MISTRAL_API_KEY"),
            # )

            self._llm = ChatOpenAI(
                # model="gpt-4o-mini",
                model="gpt-4o",
                # model="ft:gpt-4o-mini-2024-07-18:prompt-infection::Au7BGrZS",  # PIE-finetuned
                temperature=0.7,
                openai_api_key=os.getenv("OPENAI_API_KEY"),
                openai_organization=os.getenv("OPENAI_ORG"),
            )
        return self._llm

    def extract_reflection(self, text: str) -> str:
        pattern = r"<reflection>(.*?)</reflection>"
        matches = re.findall(pattern, text, re.DOTALL)
        return matches[0].strip() if matches else ""

    def extract_strategies(self, text: str) -> list:
        pattern = r"strategy:\s*(.*?)\n"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []

    def extract_codes(self, text: str) -> list:
        # Match both ```cpp and ``` code blocks
        pattern = r"code:\s*```(?:cpp)?\n(.*?)\n```"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []

    def extract_start_line(self, text: str) -> list:
        pattern = r"start_line:\s*(.*?)\n"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []

    def extract_end_line(self, text: str) -> list:
        pattern = r"end_line:\s*(.*?)\n"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []


    def process_code(self, code: str) -> str:
        """
        Process the captured code string to remove triple backticks if present.
        """
        pattern = r"```(?:\w+)?\n(.*?)\n```"
        match = re.search(pattern, code, re.DOTALL)
        if match:
            return match.group(1)
        return code


    def parse(self, output: str, operation_type: str="Mutation") -> List[Dict]:
        operations = []
        # Split text into individual mutations, ignoring the empty first split
        if operation_type == "Mutation":
            operation_blocks = re.split(r"<Mutation \d+>", output)[1:]
        elif operation_type == "Crossover":
            operation_blocks = re.split(r"<Crossover \d+>", output)[1:]

        print("\033[31mOperation blocks:\033[0m")
        print(f"\033[31m{len(operation_blocks)}\033[0m")

        for block in operation_blocks:
            operation = {"strategy": "", "code_changes": []}

            # Extract strategy
            strategy_match = re.search(r"strategy: (.+)", block)
            if strategy_match:
                operation["strategy"] = strategy_match.group(1).strip()

            # Extract code changes with a pattern that matches all fields
            change_pattern = re.compile(
                r"start line number: (\S+)\s+"  # \S+ allows non-numeric like "sl1"
                r"start line code: (.*?)\s+"
                r"end line number: (\S+)\s+"  # \S+ for "el1"
                r"end line code: (.*?)\s+"
                r"code:\s*(.*?)(?=\s*start line number:|\Z)",  # Until next section or end
                re.DOTALL,
            )
            change_sections = change_pattern.findall(block)

            for change in change_sections:
                # Attempt to convert line numbers to int, keep as string if it fails
                try:
                    start_line = int(change[0])
                except ValueError:
                    start_line = change[0]
                try:
                    end_line = int(change[2])
                except ValueError:
                    end_line = change[2]

                operation["code_changes"].append(
                    {
                        "start_line_number": start_line,
                        "start_line_code": change[1].strip(),
                        "end_line_number": end_line,
                        "end_line_code": change[3].strip(),
                        "new_code": self.process_code(change[4].strip()),
                    }
                )

            operations.append(operation)

        return operations




class LLMCrossover(LLMBase):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing crossover operations, aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate {num_offsprings} crossover codes from given parent codes.
            A lower fitness score means better performance.

            Each crossover operation should involve selecting parent codes, combining them strategically to produce optimized offspring.
            The strategy should clearly describe how the parent codes are combined to form the crossover.
            Balancing exploration and exploitation is key to success.

            Here is the original source code to be optimized:
            {original_source_code}

            Note that the code is quite long. So I prepended a code line number to each line of the code.
            Your new code could be shorter or longer than the codes to be replaced.
            For example, if you want to replace the code in line A to B, you should write the new code like:

            <Crossover N>
            strategy: Given that ~, combine A from Parent X with B from Parent Y
            start line number: A
            start line code: Line A code (every single letter, number, and symbol should be included)
            end line number: B
            end line code: Line B code (every single letter, number, and symbol should be included)
            code:
            ```
            // new code
            ```

            (and optionally more lines to replace if necessary to make the code valid)
            start line number: C
            start line code: Line C code (every single letter, number, and symbol should be included)
            end line number: D
            end line code: Line D code (every single letter, number, and symbol should be included)
            code:
            ```
            // new code
            ```
            Here, "start line number" and "end line number" are the line numbers of the original code to be replaced.
            "start line code" and "end line code" are the codes of the start and end lines.
            The new code could be shorter or longer than the codes to be replaced.
            As you can see, you can replace multiple sections of the code if necessary (like when including a new library, etc.)
            Important note for the end line. If the target end line is just a bracket, you should write it so.
            If you fail to include the bracket and just write the new code, you might end up with two closing brackets and the code will not compile.
            
            Your goal is to return the best {num_offsprings} crossover codes.
            Your code should be a valid C++ code that can be compiled and run.
            Here's an example an an output format. For the third crossover, the example output is:

            Now, here are the parent codes with their fitness scores.
            Each parent code is provided as a code diff.
            So, for each parent, some of the lines are removed and some of the lines are added.
            {codes_and_fitnesses}
            
            We highly want diverse crossovers.
            For each crossover block, the output format should always start with <Crossover N>.
            And then obey the output format like below.
            start line number: A
            start line code: Line A code
            end line number: B
            end line code: Line B code
            code:
            ```
            // new code
            ```

            Strictly follow the output format.
            - Don't use a markdown! D n't decorate the texts!
            - dont use ** to wrap the strategy or code. No asteriks for wrapping!
            - dont use ```cpp. Only do ```
            - Otherwise, your output will be rejected.

            Return the best {num_offsprings} crossovers:
            """
        )
    )


    def get_code_diff(self, code1, code2):
        # Split the code into lines
        s1 = code1.splitlines(keepends=False)
        s2 = code2.splitlines(keepends=False)
        
        # Use Differ to compare lines
        differ = difflib.Differ()
        diff = list(differ.compare(s1, s2))
        
        # Collect only changes
        output = []
        line_num1 = 0  # Original file line number
        line_num2 = 0  # New file line number
        
        for line in diff:
            if line.startswith('- '):
                line_num1 += 1
                output.append(f"Line {line_num1} (removed): {line[2:]}")
            elif line.startswith('+ '):
                line_num2 += 1
                output.append(f"Line {line_num2} (added): {line[2:]}")
            elif line.startswith('  '):
                line_num1 += 1
                line_num2 += 1
                # Explicitly skip unchanged lines
            # Ignore '? ' lines for simplicity unless you want character-level hints
        
        return "\n".join(output) if output else "No changes detected."
            
    def format_crossover_parents(self, code_diffs, fitnesses):
        return "\n\n".join(
            f"<Parent {i + 1}>\nCode diff: \n```\n{code_diff}\n```\nFitness score: {fitness}"
            for i, (code_diff, fitness) in enumerate(zip(code_diffs, fitnesses))
        )

    def crossover(self, parent_codes, parent_fitnesses, num_offsprings, original_source_code):
        max_attempts = 3
        attempt = 0
        crossovers = []

        # extract a code from each parent and generate a diff
        parent_code_diffs = [self.get_code_diff(original_source_code, code) for code in parent_codes]
        codes_and_fitnesses = self.format_crossover_parents(parent_code_diffs, parent_fitnesses)

        # Prepend the code line number to each code line
        original_source_code = "\n".join(
            [f"Line {i}: {line}" for i, line in enumerate(original_source_code.split("\n"))]
        )


        while attempt < max_attempts:
            attempt += 1
            messages = self.prompt.format_messages(
                original_source_code=original_source_code,
                codes_and_fitnesses=codes_and_fitnesses,
                num_offsprings=num_offsprings,
            )

            response = ""
            for chunk in self.llm.stream(messages):
                print(chunk.content, end="", flush=True)
                response += chunk.content

            crossovers = self.parse(response, operation_type="Crossover")

            strategies = [crossover["strategy"] for crossover in crossovers]
            code_changes = [crossover["code_changes"] for crossover in crossovers]

            if not strategies or not code_changes:
                if not strategies:
                    print("No strategies found, retrying...")
                if not code_changes:
                    print("No codes found, retrying...")
                continue

            if strategies and code_changes and len(strategies) == len(code_changes):
                return strategies, code_changes

            print("Mismatch or empty strategies/codes, retrying...")

        raise ValueError(
            "Failed to generate valid crossovers after 3 attempts."
        )


class LLMReflection(LLMBase):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            You are an expert developer. Previously, you were given a code and you wrote a new code
            to make the code faster by improving the fitness score.

            This was the parent code you were given:
            {parent_codes}

            This was the fitness score of the parent code:
            {parent_fitnesses}

            This was the new code you wrote:
            {child_code}

            Here is the run result:
            {run_result}

            Now, you need to reflect on this. The purpose is to learn what strategy worked, what didn't,
            so that you can later use this compressed knowledge to write better codes.
            For example, if the new code is faster, you should reflect on what strategies made it faster.
            If the new code is slower, you should reflect on what strategies made it slower.
            If the test or compile failed, you should reflect on what went wrong.
            The reflection should be concise and to the point, no more than 100 words. You may include a bit of code.

            After some thoughts, start your reflection with <reflection> tag and end with </reflection> tag.
            Now, please reflect on the new code and the run result:
            """
        )
    )

    def reflect(self, child, run_result):
        print("Run result: ", run_result)
        parent_codes = child.parent_codes
        parent_fitnesses = child.parent_fitnesses
        child_code = child.get_patched_code()

        messages = self.prompt.format_messages(
            parent_codes=parent_codes,
            parent_fitnesses=parent_fitnesses,
            child_code=child_code,
            run_result=run_result,
        )

        max_attempts = 2
        attempt = 0
        while attempt < max_attempts:
            attempt += 1
            response = self.llm.invoke(messages)
            reflection = self.extract_reflection(response.content)
            if reflection:
                return reflection

        return ""


class LLMMutation(LLMBase):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing mutation operations, 
            aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate {num_offsprings} mutations of the given code.
            A lower fitness score means better performance.

            Each mutation operation should involve selecting specific parts of the code, 
            such as import packages, lines, or blocks, and applying diverse strategies to optimize them.
            The strategy should clearly describe the focus area and the intended optimization.
            Balancing exploration and exploitation is key to success.
            Your code should be a valid C++ code that can be compiled and run.
            Your goal is to return the best {num_offsprings} optimization mutations.

            Also, here are some reflections that you may use to generate the mutation:
            {reflections}
            You wrote these reflections yourself in the past so that you can learn from them and write a better, faster code without making the same mistakes again.
            However, note that you should not strictly follow the reflections because we want you to explore and discover new strategies.

            Now, here's the code to mutate:
            {code}
            Fitness score: {fitness}

            Return the best {num_offsprings} mutations. We highly want diverse mutations.

            [ON OUTPUT FORMAT]
            Note that the code is quite long. So I prepended a code line number to each line of the code.
            Your new code could be shorter or longer than the codes to be replaced.
            For example, if you want to replace the code in line A to B, you should write the new code like:

            <Mutation 1>
            strategy: Focus on the lines A:B that do X, which could be optimized by Y.
            start line number: A
            start line code: Line A code (every single letter, number, and symbol should be included)
            end line number: B
            end line code: Line B code (every single letter, number, and symbol should be included)
            code:
            ```
            // new code
            ```

            (and optionally more lines to replace if necessary to make the code valid)
            start line number: C
            start line code: Line C code (every single letter, number, and symbol should be included)
            end line number: D
            end line code: Line D code (every single letter, number, and symbol should be included)
            code:
            ```
            // new code
            ```
            Here, "start line number" and "end line number" are the line numbers of the code to be replaced.
            "start line code" and "end line code" are the codes of the start and end lines.
            The new code could be shorter or longer than the codes to be replaced.
            As you can see, you can replace multiple sections of the code if necessary (like when including a new library, etc.)
            Important note for the end line. If the target end line is just a bracket, you should write it so.
            If you fail to include the bracket and just write the new code, you might end up with two closing brackets and the code will not compile.
            
            Strictly follow the output format.
            - Don't use a markdown! Don't decorate the texts!
            - dont use ** to wrap the strategy or code. No asteriks for wrapping!
            - dont use ```cpp. Only do ```
            - Otherwise, your output will be rejected.

            When I replace the target code lines with your new code,
            the new patched code should be a valid .cc code that can be compiled and run.
            So you cannot simply remove any code without caution.
            Please write a fast, valid C++ code.

            In summary, first analyze the code and generate any possible sources of inefficiency.
            Then write the mutations for a faster, more efficient code.
            Sometimes, you can think outside the box.
            Sometimes, you can think of some known optimization patterns.

            For a mutation block, the output format should always start with <Mutation N>.
            And then obey the output format like below.
            start line number: A
            start line code: Line A code
            end line number: B
            end line code: Line B code
            code:
            ```
            // new code
            ```
            """
        )
    )

    debug_prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing mutation operations, 
            aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate {num_offsprings} mutations of the given code.
            A lower fitness score means better performance.

            Each mutation operation should involve selecting specific parts of the code, 
            such as import packages, lines, or blocks, and applying diverse strategies to optimize them.
            The strategy should clearly describe the focus area and the intended optimization.
            Balancing exploration and exploitation is key to success.
            Your code should be a valid C++ code that can be compiled and run.
            Your goal is to return the best {num_offsprings} optimization mutations.

            Also, here are some reflections that you may use to generate the mutation:
            {reflections}
            You wrote these reflections yourself in the past so that you can learn from them and write a better, faster code without making the same mistakes again.
            However, note that you should not strictly follow the reflections because we want you to explore and discover new strategies.

            Now, here's the code to mutate:
            {code}
            Fitness score: {fitness}

            Return the best {num_offsprings} mutations. We highly want diverse mutations.

            [ON OUTPUT FORMAT]
            First, analyze the code and do some thinking.

            Note that the code is quite long. So I prepended a code line number to each line of the code.
            Your new code could be shorter or longer than the codes to be replaced.
            For example, if you want to replace the code in line A to B, you should write the new code like:

            <Mutation 1>
            strategy: Focus on the lines A:B that do X, which could be optimized by Y.
            start line number: A
            start line code: Line A code (every single letter, number, and symbol should be included)
            end line number: B
            end line code: Line B code (every single letter, number, and symbol should be included)
            code:
            ```
            // new code
            ```
            Here, "start line number" and "end line number" are the line numbers of the code to be replaced.
            "start line code" and "end line code" are the codes of the start and end lines.
            The new code could be shorter or longer than the codes to be replaced.
            As you can see, you can replace multiple sections of the code if necessary (like when including a new library, etc.)
            Important note for the end line. If the target end line is just a bracket, you should write it so.
            If you fail to include the bracket and just write the new code, you might end up with two closing brackets and the code will not compile.
            
            Strictly follow the output format.
            - Don't use a markdown! Don't decorate the texts!
            - dont use ** to wrap the strategy or code. No asteriks for wrapping!
            - dont use ```cpp. Only do ```
            - Otherwise, your output will be rejected.

            When I replace the target code lines with your new code,
            the new patched code should be a valid .cc code that can be compiled and run.
            So you cannot simply remove any code without caution.
            Please write a fast, valid C++ code.

            Only change upto 1 line of code. Prioritize the code that is most likely to be compiled.

            For a mutation block, the output format should always start with <Mutation N>.
            And then obey the output format like below.
            start line number: A
            start line code: Line A code
            end line number: B
            end line code: Line B code
            code:
            ```
            // new code
            ```
            """
        )
    )


    def mutate(
        self,
        source_code: str,
        target_code: str,
        target_fitness: int,
        num_offsprings: int,
        reflections: list,
    ) -> str:
        max_attempts = 3
        attempt = 0
        num_offsprings = max(1, num_offsprings)

        # Prepend the code line number to each code line
        target_code = "\n".join(
            [f"{i}: {line}" for i, line in enumerate(target_code.split("\n"))]
        )

        if self.is_debugging:
            # print("\033[33m" + target_code + "\033[0m")
            with open("/home/luke/magpie/target_code.txt", "w") as f:
                f.write(target_code)
            prompt = self.debug_prompt
        else:
            prompt = self.prompt

        while attempt < max_attempts:
            attempt += 1
            messages = prompt.format_messages(
                code=target_code,
                fitness=target_fitness,
                num_offsprings=num_offsprings,
                reflections=reflections,
            )
            try:
                # response = self.llm.invoke(messages)
                response = ""
                for chunk in self.llm.stream(messages):
                    print(chunk.content, end="", flush=True)
                    response += chunk.content

            except Exception as e:
                print("Error: ", e)
                time.sleep(1)
                continue

            mutations = self.parse(response)
            strategies = [mutation["strategy"] for mutation in mutations]
            code_changes = [mutation["code_changes"] for mutation in mutations]

            if not strategies:
                print("No strategies found, retrying...")
                continue
    
            if not code_changes:
                print("No codes found, retrying...")
                continue

            if len(strategies) != len(code_changes):
                print("Mismatch or empty strategies/codes, retrying...")
                continue

            if (
                strategies
                and code_changes
                and len(strategies) == len(code_changes)
            ):
                return strategies, code_changes

            print("Num offsprings: ", num_offsprings)
            print("Mismatch or empty strategies/codes, retrying...")

        raise ValueError(
            "Failed to generate valid mutations after 3 attempts."
        )
    
        

class LLMOneShotOptimization(LLMMutation):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing mutation operations, aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate the best optimized code of the given code.
            A lower fitness score means better performance.

            Here's the code to optimize:
            {code}

            Return the best optimized code wrapped in ```cpp and ```:
            """
        )
    )


# Usage example:
if __name__ == "__main__":
    optimizer = LLMMutation()

    sample_code = """
    void bubbleSort(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    """

    optimized = optimizer.optimize(sample_code)
    print(optimized)
