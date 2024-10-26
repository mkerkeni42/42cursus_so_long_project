# So Long: Ice Cream Frenzy 🍦

## Project Overview 🎮

**so_long** is a basic **2D game** created using the **MiniLibX library**. 
The goal of the game is to collect all the ice creams on the map and then make your way to the red car 🚗 to win! 
In the bonus version, you have to **avoid broccoli enemies** 🥦 while collecting ice creams, and if you touch the broccoli **three times**, you lose 💥. 

<img src="screenshots/start_image.png" alt="My Image" height="250"/> <img src="screenshots/game.png" alt="My Image" height="250"/> 
<img src="screenshots/winning_image.png" alt="My Image" height="250"/> <img src="screenshots/game_over_image.png" alt="My Image" height="250"/> 


## How To Use 🕹️

1. **Compile the game** using `make`.
   
2. **Run the game** with the command:
   ```
   ./so_long maps/map.ber
3. **Move the character** using the W, A, S, D keys to collect all the ice creams.  
  (*This program is designed to run on **Linux**. To use it on **macOS**, simply update the key codes in `so_long_bonus/so_long_bonus.h`*)  
   
5. For the bonus version, compile with `make bonus` and run the game with:
   ```
   ./so_long_bonus maps/map_bonus.ber  
## Technologies Used ⚙️

- <img src="https://cdn.worldvectorlogo.com/logos/c-1.svg" alt="C" width="40" height="40"/>
- MiniLibX Library 📦

## Challenges I Faced 🧠
Some of the key challenges in this project included:

- **Coding with MiniLibX**: It was difficult working with this low-level library as it provides only the basics for window and event management, which made things like smooth graphics and event handling harder to implement.
- **Creating Game Logic**: Balancing game mechanics, like the interactions between the player, ice creams, and broccoli in the bonus part, was tricky but rewarding to figure out.

## What I Learned 🧩
This project taught me the fundamentals of **creating a video game from scratch**, including:

- Managing **game states** 🕹️
- **Player movement** 👾
- **Handling events** like keypresses and collisions 💥

While working on the bonus part, I added basic **enemy behavior** 👹 and **life management**, which made the game more engaging.
Even though a more advanced framework might have made coding the game easier, tackling challenges with simpler tools made the learning experience more rewarding 🌟 and helped me grow as a developer 📈.
