from langchain_openai import ChatOpenAI
from langchain.prompts import ChatPromptTemplate
import os
import re
import random
import textwrap


class LLMBase:
    def __init__(self):
        self.id = 0
        self._llm = None

    @property
    def llm(self):
        # Lazy load the LLM to avoid deepcopy/pickle errors with thread locks
        if self._llm is None:
            self._llm = ChatOpenAI(
                model="gpt-4o-mini",
                temperature=0.7,
                openai_api_key=os.getenv("OPENAI_API_KEY"),
                openai_organization=os.getenv("OPENAI_ORG"),
            )
        return self._llm

    def extract_strategies(self, text: str) -> list:
        pattern = r"strategy:\s*(.*?)\n"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []

    def extract_codes(self, text: str) -> list:
        pattern = r"code:\s*```cpp\n(.*?)\n```"
        matches = re.findall(pattern, text, re.DOTALL)
        return [match.strip() for match in matches] if matches else []


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

            Your goal is to return the best {num_offsprings} crossover codes.
            Here's an example an an output format. The third mutation, the example output is:

            <Crossover 3>
            strategy: Combine function A from Parent 1 (fitness: X) with function B from Parent 2 (fitness: Y).
            code:
            ```cpp
            // your crossover code
            ```

            Here are the parent codes with their fitness scores:
            {codes_and_fitnesses}

            Return the best {num_offsprings} crossovers.
            Strictly follow the output format:
            """
        )
    )

    def crossover(self, codes_and_fitnesses, num_offsprings):
        messages = self.prompt.format_messages(
            codes_and_fitnesses=codes_and_fitnesses,
            num_offsprings=num_offsprings,
        )
        response = self.llm.invoke(messages)

        print("Response: ", response.content)

        strategies = self.extract_strategies(response.content)
        codes = self.extract_codes(response.content)

        crossovers = []
        for strategy, code in zip(strategies, codes):
            crossovers.append({"strategy": strategy, "crossover_code": code})

        if not strategies or not codes or len(strategies) != len(codes):
            raise ValueError(
                "Mismatch between strategies and codes or one of them is empty."
            )
        return crossovers


class LLMMutation(LLMBase):
    prompt = ChatPromptTemplate.from_template(
        textwrap.dedent(
            """
            We are implementing a genetic algorithm to optimize code by performing mutation operations, aiming to improve its fitness score (runtime).
            As an expert C++ developer, your task is to generate {num_offsprings} mutations of the given code.
            A lower fitness score means better performance.

            Each mutation operation should involve selecting specific parts of the code, such as import packages, lines, or blocks, and applying diverse strategies to optimize them.
            The strategy should clearly describe the focus area and the intended optimization.

            Your goal is to return the best {num_offsprings} optimization mutations.
            When printing the third mutation, the example output format is:
            
            <Mutation 3>
            strategy: Focus on the line X that does Y, which could be optimized by Z.
            code:
            ```cpp
            // your mutated code
            ```

            Here's the code to mutate:
            {code}
            Fitness score: {fitness}

            Return the best {num_offsprings} mutations.
            Strictly follow the output format:
            """
        )
    )

    def mutate(
        self,
        source_code: str,
        target_code: str,
        target_fitness: int,
        num_offsprings: int,
    ) -> str:
        messages = self.prompt.format_messages(
            code=target_code,
            fitness=target_fitness,
            num_offsprings=num_offsprings,
        )
        response = self.llm.invoke(messages)

        print("Response: ", response.content)

        strategies = self.extract_strategies(response.content)
        codes = self.extract_codes(response.content)

        if not strategies or not codes or len(strategies) != len(codes):
            raise ValueError(
                "Mismatch between strategies and codes or one of them is empty."
            )

        return strategies, codes

    def mutate_debugging(
        self,
        source_code: str,
        target_code: str,
        target_fitness: int,
        num_offsprings: int,
    ) -> str:
        mutations = []
        for _ in range(num_offsprings):
            mutation_strategy = f"Strategy {self.id}"
            mutated_code = f"{target_code} // {self.id}"
            mutations.append(
                {
                    "strategy": mutation_strategy,
                    "mutated_code": mutated_code,
                }
            )
            self.id += 1
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
