from langchain_openai import ChatOpenAI
from langchain.prompts import ChatPromptTemplate
import os
import re


class LLMMutator:
    def __init__(self):
        self._llm = None
        self.prompt = ChatPromptTemplate.from_template(
            """You are an expert C++ developer focused on optimization.
        Analyze the following code and suggest optimized version.
        Focus on:
        - Time complexity
        - Modern C++ practices
        - Performance improvements

        Identify any code that can be removed or simplified (e.g. unnecessary delays, unnecessary loops, etc.)

        Here's the code to optimize:
        {code}

        Return the optimized code wrapped with ``` and ``` markers.
        """
        )

    @property
    def llm(self):
        # Lazy load the LLM to avoid deepcopy/pickle errors with thread locks
        # ChatOpenAI contains non-pickleable thread locks, so we initialize it
        # only when needed rather than in __init__
        if self._llm is None:
            self._llm = ChatOpenAI(
                model="gpt-4o-mini",
                temperature=0.7,
                openai_api_key=os.getenv("OPENAI_API_KEY"),
                openai_organization=os.getenv("OPENAI_ORG"),
            )
        return self._llm

    def _extract_code_block(self, text: str) -> str:
        """Extract code between triple backticks from text.

        Args:
            text (str): Text containing code block between ``` markers

        Returns:
            str: Extracted code or empty string if no code block found
        """
        pattern = r"```(?:cpp)?\s*(.*?)```"
        match = re.search(pattern, text, re.DOTALL)
        return match.group(1).strip() if match else ""

    def mutate(self, code: str) -> str:
        messages = self.prompt.format_messages(code=code)
        response = self.llm.invoke(messages)
        return self._extract_code_block(response.content)


# Usage example:
if __name__ == "__main__":
    optimizer = LLMMutator()

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
