from langchain_openai import ChatOpenAI
from langchain_mistralai import ChatMistralAI
from langchain.prompts import ChatPromptTemplate
import os
import re
import textwrap
import time
import re
from typing import List, Dict


class LLMBase:
    def __init__(self):
        self.id = 0
        self._llm = None

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


class LLMCrossover(LLMBase):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing crossover operations, aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate {num_offsprings} crossover codes from given parent codes.
            A lower fitness score means better performance.

            Here are some examples of successful code optimizations:

            ```cpp
            #include <bits/stdc++.h>
            using namespace std;

            int main() {{
                string s;
                cin >> s;
                int a = 0, z = 0;
                for(int i = 0; i < s.size(); i++) {{
                    if (s[i] == 'A') {{
                        a = i;
                        break;
                    }}
                }}
            ```

            can be optimized to:
            ```cpp
            #include<cstdio>
            #include<algorithm>
            using namespace std;
            char str[200005];
            int main(){{
                scanf("%s",str);
                int ans = 0;
                int a=-1;
                for(int i=0;str[i];i++){{
                    if(str[i]=='Z'){{
                        if(a!=-1)
                            ans = max(ans,i-a);
                    }}else if(str[i]=='A' && a==-1)
                        a = i;
                }}
                printf("%d\n",ans+1);
                return 0;
            }}
            ```

            For another example,
            ```cpp
            #include <cstdio>
            #include <cstring>
            #include <algorithm>
            #include <iostream>
            using namespace std;

            typedef long long ll;
            const int maxn = 100000;
            int n;
            long long a[maxn], b[maxn];
            int main(void) {{
                cin >> n;
                for(int i = 0; i < n; ++i) {{
                    cin >> a[i] >> b[i];
                }}
            }}
            ```
            can be optimized to:
            ```cpp
            #include <cstdio>
            #include <cstring>
            #include <algorithm>
            using namespace std;
            typedef long long li;
            const int maxn = 1e5;
            int n, a[maxn], b[maxn];
            int main(void) {{
                scanf("%d", &n);
                for (int i = 0; i < n; ++i) {{
                    scanf("%d%d", a + i, b + i);
                }}
                li ans = 0;
                for (int i = n - 1; i >= 0; --i) {{
                    li cur = a[i] + ans;
                    li tar = (cur + b[i] - 1) / b[i] * b[i];
                    ans += tar - cur;
                }}
                printf("%lld\n", ans);
            }}
            ```
            The above are only examples.

            Each crossover operation should involve selecting parent codes, combining them strategically to produce optimized offspring.
            The strategy should clearly describe how the parent codes are combined to form the crossover.
            Balancing exploration and exploitation is key to success.

            Your goal is to return the best {num_offsprings} crossover codes.
            Your code should be a valid C++ code that can be compiled and run.
            Here's an example an an output format. For the third crossover, the example output is:

            <Crossover 3>
            strategy: Combine function A from Parent 1 (fitness: X) with function B from Parent 2 (fitness: Y).
            code:
            ```cpp
            // your crossover code
            ```

            Now, here are the parent codes with their fitness scores:
            {codes_and_fitnesses}

            Return the best {num_offsprings} crossovers. We highly want diverse crossovers.
            Strictly follow the output format (e.g. strategy: ..., code: ...)  (dont use ** to wrap the strategy or code):
            """
        )
    )

    def crossover(self, codes_and_fitnesses, num_offsprings):
        max_attempts = 3
        attempt = 0
        crossovers = []

        while attempt < max_attempts:
            attempt += 1
            messages = self.prompt.format_messages(
                codes_and_fitnesses=codes_and_fitnesses,
                num_offsprings=num_offsprings,
            )
            response = self.llm.invoke(messages)

            print(f"Attempt {attempt}: Response: ", response.content)

            strategies = self.extract_strategies(response.content)
            codes = self.extract_codes(response.content)

            if strategies and codes and len(strategies) == len(codes):
                for strategy, code in zip(strategies, codes):
                    print("Strategy: ", strategy)
                    print("Code: ", code)
                    crossovers.append(
                        {"strategy": strategy, "crossover_code": code}
                    )
                return crossovers

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
            First, analyze the code and do some thinking.

            Note that the code is quite long. So I prepended a code line number to each line of the code.
            Your new code could be shorter or longer than the codes to be replaced.
            For example, if you want to replace the code in line A to B, you should write the new code like:

            <Mutation 1>
            strategy: Focus on the lines A:B that do X, which could be optimized by Y.
            start line number: A
            start line code: Line A code
            end line number: B
            end line code: Line B code
            code:
            ```
            // new code
            ```

            (and optionally more lines to replace if necessary to make the code valid)
            start line number: C
            start line code: Line C code
            end line number: D
            end line code: Line D code
            code:
            ```
            // new code
            ```
            Here, "start line number" and "end line number" are the line numbers of the code to be replaced.
            "start line code" and "end line code" are the codes of the start and end lines.
            The new code could be shorter or longer than the codes to be replaced.
            As you can see, you can replace multiple sections of the code if necessary (like when including a new library, etc.)

            First, analyze the given code and generate any possible sources of inefficiency.
            And then write the mutations.
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
            Then write the mutations.

            For a mutation block, the output format should always start with <Mutation N>.
            And then obey the output format like below.
            start line number: A
            start line code: Line A code
            end line number: B
            end line code: Line B code
            code:

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

        while attempt < max_attempts:
            attempt += 1
            messages = self.prompt.format_messages(
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

    def parse(self, output: str) -> List[Dict]:
        mutations = []
        # Split text into individual mutations, ignoring the empty first split
        mutation_blocks = re.split(r"<Mutation \d+>", output)[1:]

        for block in mutation_blocks:
            mutation = {"strategy": "", "code_changes": []}

            # Extract strategy
            strategy_match = re.search(r"strategy: (.+)", block)
            if strategy_match:
                mutation["strategy"] = strategy_match.group(1).strip()

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

                mutation["code_changes"].append(
                    {
                        "start_line_number": start_line,
                        "start_line_code": change[1].strip(),
                        "end_line_number": end_line,
                        "end_line_code": change[3].strip(),
                        "new_code": change[4].strip(),
                    }
                )

            mutations.append(mutation)

        return mutations


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
