# AI Workflow Used in Mission Control

## Overview

This file explains how I used agentic AI tools during the development of the Mission Control Card Game project. My goal was not to let AI create everything blindly, but to use it in a controlled and productive way to improve speed, structure, and iteration quality.

---

## Tools Used

During development, I used:

- ChatGPT for documenting the project idea, goals, and expected output
- Trae AI as the coding environment
- Claude model inside Trae AI for code generation and refinement

---

## Step 1: Planning the Project

Before asking an AI tool to generate code, I first clarified the project requirements.

I used ChatGPT to help me:
- organize my game idea
- describe the gameplay clearly
- define project goals
- explain the expected output
- structure the concept in a way that an AI coding tool could understand better

This step was important because good AI outputs depend heavily on how clearly the task is defined.

---

## Step 2: Giving Structured Instructions to Trae AI

After documenting the project properly, I used that explanation to guide Trae AI.

Instead of vague prompts, I tried to provide:
- the purpose of the game
- expected gameplay behavior
- class responsibilities
- desired output structure
- implementation direction

This made the AI assistance more targeted and useful.

---

## Step 3: Working Step by Step

One of the biggest lessons from this project was that asking AI to build everything at once is usually not the best strategy.

I worked step by step:
- first on structure
- then on classes
- then on specific logic
- then on revisions and corrections

This helped me:
- keep control over the code
- detect issues earlier
- understand the generated code better
- make more accurate refinements

Step-by-step prompting gave me much better output than one-shot prompting.

---

## Step 4: Reviewing AI Output Carefully

I did not assume the AI output was correct just because it was generated quickly.

After each step, I reviewed:
- whether the code matched my requirements
- whether the class structure made sense
- whether the logic was aligned with my intended gameplay
- whether the generated code needed refinement or correction

This review process was essential because AI can generate code that looks fine at first but still does not fully meet the actual requirement.

---

## Step 5: Testing and Validation

Testing was a major part of the workflow.

I validated the generated code by:
- checking if it matched the expected behavior
- testing whether the structure worked in my target setup
- reviewing whether the implementation actually reflected the documented game idea

This project reinforced that AI can help with speed, but correctness still depends on human testing and judgment.

---

## What Worked Well

Using agentic AI improved productivity in several ways:

- faster class scaffolding
- quicker iteration on logic
- easier refinement of repetitive coding tasks
- faster movement from concept to working structure
- better momentum during development

The biggest productivity gain came from using AI as a collaborative assistant rather than a replacement for my own thinking.

---

## Main Challenge Faced

A major challenge was that Trae AI was only available on Windows, while I wanted the project workflow and testing to be based on Linux.

Because of this, I had difficulty testing simultaneously in the same environment where I was generating code. I had to shift my IDE and workflow to validate the code properly.

This created extra effort in:
- cross-environment testing
- verifying compatibility
- making sure the generated code worked in the intended setup

---

## What I Learned

This project taught me several important things about using agentic AI in software development:

- clear documentation leads to better AI output
- step-by-step prompting gives better control
- human review is always necessary
- testing cannot be skipped
- AI is strongest when used as an assistant, not a substitute
- productivity improves most when the developer stays actively involved

---

## Final Reflection

This project was not just a C++ card game project. It was also a practical learning experience in how to use agentic AI effectively in a real coding workflow.

It showed me that responsible AI use in software development means:
- planning first
- guiding carefully
- reviewing thoroughly
- testing consistently
- and keeping ownership of the final result
