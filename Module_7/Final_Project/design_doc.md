# **Design Document Template — Project 4**

**Name:** Janiya Barrett

**Track:** B 

**Project Title:** MasterMind Quiz Engine

**One-sentence pitch:** A dynamic quiz application that loads difficulty-based questions from a file, tracks player scoring, and adds pressure with a countdown timer.

---

## **1\. The Problem**

Standard quiz apps are often hard-coded and static. This program provides a reusable engine where users can load different question sets, choose a difficulty level (Easy, Medium, Hard), and test their knowledge against a clock. It’s designed for students or trivia buffs who want a customizable challenge.

---

## **2\. State Inventory**

| Data | Type | What Changes It |
| :---- | :---- | :---- |
| question\_bank | List/Array of Objects | Loaded once at the start from the file |
| current\_score | Integer | Answering a question correctly |
| difficulty | Text/String | User selection at the main menu |
| time\_remaining | Integer | The clock ticking down every second |
| question\_index | Integer | Moving to the next question after an answer |
| is\_game\_over | True/False | Timer hitting zero or running out of questions |

---

## **3\. Function / Component Map**

| Function or Component | What It Does | Inputs | Outputs |
| :---- | :---- | :---- | :---- |
| load\_questions() | Reads the JSON/CSV file and filters by difficulty | filename, difficulty | List of questions |
| display\_menu() | Shows difficulty options and gets user choice | none | string (difficulty) |
| run\_timer() | Handles the countdown logic | seconds | none (updates state) |
| render\_question() | Prints the question and multiple-choice options | question\_object | none |
| validate\_answer() | Compares user input to the correct answer | user\_input, correct\_answer | boolean |
| calculate\_final\_grade() | Converts raw score into a percentage/rank | score, total | string (Grade/Rank) |
| save\_high\_score() | Appends the user's final score to a leaderboard file | name, score | none |

---

## **4\. User Flow**

**Main path:**

1. The program starts and displays a welcome message and difficulty selection (Easy/Medium/Hard).  
2. The user selects a difficulty, and the program loads the corresponding questions from the data file.  
3. The first question is displayed, and the countdown timer starts.  
4. The user enters their answer; the program immediately tells them if they are right or wrong and updates the score.  
5. Steps 3-4 repeat until all questions are answered or the timer hits zero.  
6. The final score is displayed, and the user is asked if they want to save their result to the leaderboard.

**Key branches:**

* **If the timer hits zero:** The game stops immediately, even if questions remain, and jumps to the results screen.  
* **If the question file is missing:** The program displays a friendly error and exits safely instead of crashing.  
* **If input is invalid:** (e.g., user types "K" for a 1-4 multiple choice), the program asks again without penalizing the score.

---

## **5\. What Could Go Wrong**

| Risk | Plan |
| :---- | :---- |
| **Timer and Input collision** | If the timer runs out while the user is typing, use a non-blocking input method or check the timestamp after input. |
| **File formatting errors** | Use a try/except block when loading the file to catch syntax errors in the question data. |
| **Empty question set** | If a difficulty level has no questions in the file, default to "General" or alert the user. |

---

## **6\. What I'll Ask AI to Help With**

| Task | Why AI Help Makes Sense |
| :---- | :---- |
| **Threading/Timer logic** | Running a countdown in the background while waiting for user input can be syntactically tricky. |
| **File Pathing** | Ensuring the program finds the questions.json file regardless of whether it's run on Mac or Windows. |
| **Regex for input** | Helping me write a quick check to make sure the user only types valid characters. |

---

## **7\. What I'll Do Myself (No AI)**

1. **The Core Loop:** I will write the while loop that keeps the game running and moves from one question to the next.  
2. **Score Logic:** I’ll design the math for how many points are awarded (perhaps more points for "Hard" mode).

---

## **8\. Scope Check**

* Can I build the C-tier version in one focused work session? **yes** (The C-tier would be a quiz with no timer and one difficulty).  
* Does every feature in my plan connect to the core interaction? **yes**  
* Have I cut anything that's "nice to have" but not essential? **yes** (I removed "Images for questions" and "Online multiplayer").

---

### **Pro-Tip for your Build:**

Since you're doing a timer, look into the time library in Python (if that's what you're using). A simple way to handle the timer without complex threading is to record the start\_time and check current\_time \- start\_time after every answer\!