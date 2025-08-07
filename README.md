# Graph Change

## What This Code Does

This repository contains a program that generates a large number of git commits with backdated timestamps. It artificially fills in your GitHub contribution graph by creating commits dated in the past, making it look like you were consistently active over a period of time.
**This repository is intended for learning & experimental use only.**

## How It Works

- The program randomly picks dates within a specified time range (e.g., the past year).
- It creates commits with those dates by modifying a JSON file and committing with the `--date` option.
- This results in a filled-in contribution graph, even if no actual work was done on those days.

## Cloning This Repository

To clone this repository to your local machine, use the following command:

```bash
git clone https://github.com/Dylanjb96/Graph-Change.git
```

## How to run it
- In the command terminal type in: **g++ -std=c++17 main.cpp random_commits.exe** (Or whichever exe name you want to add)
- Then run on the terminal **random_commits.exe** (Or whichever exe name you create)

## Consequences and Risks

- **Misrepresentation:** Using this to fake your contribution history can mislead employers, collaborators, or anyone assessing your work habits.
- **Violation of Platform Policies:** Platforms like GitHub consider this a form of dishonesty and may take action against accounts engaging in such behavior.
- **Ethical Concerns:** It undermines the value of genuine contributions and can harm your professional reputation.
- **No Real Work Done:** These commits do not reflect actual progress or learning.

## Recommendation

Use this repository **only for educational or testing purposes**. It is strongly discouraged to use this kind of technique to manipulate public contribution graphs in real projects or professional profiles.

---

*Created by Dylan B.*
