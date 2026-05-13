# **Design Document — Project 4**

**Name:** Janiya Barrett

**Track:** B

**Project Title:** MasterMind Quiz Engine

**One-sentence pitch:** A dynamic web-based quiz application that loads difficulty-based questions from a JSON file, tracks player scoring, and adds pressure with a live JavaScript countdown timer.

---

## **1\. The Problem**

Standard quiz apps are often hard-coded and static. This program provides a reusable engine where users can load different question sets, choose a difficulty level (Easy, Medium, Hard), and test their knowledge against a clock in their browser. It’s designed for students or trivia buffs who want a customizable web-based challenge.

---

## **2\. State Inventory**

| Data | Type | What Changes It |
| :---- | :---- | :---- |
| question\_bank | Array of Objects | Loaded via the Fetch API at the start |
| current\_score | Number | Answering a question correctly |
| difficulty | String | User selection on the landing page |
| time\_remaining | Number | A setInterval function ticking down every second |
| question\_index | Number | Moving to the next question after an answer |
| is\_game\_over | Boolean | Timer hitting zero or running out of questions |

---

## **3\. Function / Component Map**

| Function or Component | What It Does | Inputs | Outputs |
| :---- | :---- | :---- | :---- |
| loadQuestions() | Fetches JSON file and filters by difficulty | url, difficulty | Promise (Array) |
| initQuiz() | Sets up the UI and starts the timer | difficulty | none |
| updateTimer() | Decrements time and updates the DOM display | none | none |
| renderQuestion() | Injects question text and buttons into HTML | questionObject | none |
| checkAnswer() | Validates clicks against the correct index | userChoice | boolean |
| showResults() | Displays final score and percentage on screen | score, total | none |
| saveToLeaderboard() | Uses localStorage to save the high score | name, score | none |

---

## **4\. User Flow**

**Main path:**

1. The user opens index.html in a browser and sees a difficulty selection menu.  
2. The user selects a difficulty; JavaScript fetches the questions.json file and filters the data.  
3. The UI clears, the first question appears, and the visual countdown timer begins.  
4. The user clicks an answer button; the app provides immediate visual feedback (green/red) and updates the score.  
5. The app automatically transitions to the next question until the list is empty or time expires.  
6. A final "Game Over" screen displays the score and an input field for the leaderboard.

**Key branches:**

* **If the timer hits zero:** The input buttons are disabled immediately, and the user is sent to the results screen.  
* **If the JSON file fails to load:** A catch block displays an error message on the page asking the user to refresh.  
* **If the user clicks "Start Over":** The state variables reset to zero without a full page reload.

---

## **5\. What Could Go Wrong**

| Risk | Plan |
| :---- | :---- |
| **CORS / File Loading** | Some browsers block local JSON loading; include a note about using "Live Server" or a local environment. |
| **Timer Lag** | Ensure the setInterval is cleared properly when the game ends to prevent "ghost" timers from running. |
| **Button Spamming** | Disable answer buttons immediately after a click so the user can't click "True" five times for one question. |

---

## **6\. What I'll Ask AI to Help With**

| Task | Why AI Help Makes Sense |
| :---- | :---- |
| **Asynchronous Fetch API** | Handling Promises and .json() parsing can be tricky for a first-time setup. |
| **DOM Manipulation** | Suggestions on the cleanest way to clear and redraw the quiz container without refreshing. |
| **setInterval Logic** | Ensuring the timer stops exactly at 0 and doesn't go into negative numbers. |

---

## **7\. What I'll Do Myself (No AI)**

1. **CSS Layout:** I will design the "look and feel" using Flexbox or Grid to ensure the quiz looks good on different screen sizes.  
2. **Conditional Logic:** I will write the if/else statements that determine how many points are awarded based on the difficulty chosen.

---

## **8\. Scope Check**

* Can I build the C-tier version in one focused work session? **yes** (A simple HTML page with one set of hard-coded questions).  
* Does every feature in my plan connect to the core interaction? **yes**  
* Have I cut anything that's "nice to have" but not essential? **yes** (Removed complex animations and sounds).

