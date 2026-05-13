# **MasterMind Quiz Engine**

A dynamic web-based quiz application that loads difficulty-based questions from a JSON file, tracks player scoring, and adds pressure with a live JavaScript countdown timer.

## **Track**

**Track B**

---

## **How to Run**

Since this is a web-based application, no compilation or installation is required.

1. **Download** the project folder and ensure `index.html`, `script.js`, and `questions.json` are in the same directory.  
2. **Open** the `index.html` file in any modern web browser (Chrome, Firefox, or Edge).  
   * *Note:* Some browsers block loading local files (CORS) for security. If the questions don't load, use a "Live Server" extension in VS Code or host it on a local environment.

---

## **Project Reflection**

I’m especially proud that I used JavaScript’s **Fetch API** to load quiz questions from an external **JSON file**. This means the quiz engine is **reusable** — anyone can swap in a new *questions.json* file and instantly create a different quiz without changing the code. I also built a **non‑blocking timer** using `setInterval`, so the countdown keeps running even while the player is thinking. If I had more time, I’d work on **cleaning up the game’s state management**. Right now, the quiz uses several global variables, and I’d prefer to organize everything into a single **Quiz object** or class to make the code easier to maintain. I’d also add **localStorage support** so the leaderboard would stay saved even after closing the browser tab.