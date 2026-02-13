# Official Developer Log for [PacPac](https://github.com/YashedBin/PacPac)
---

Have fun reading!! <br>
Disclaimer: This is not the actual docs or of a much helpful information
<br>**Logs are recent to oldest**

---
## Plan for `February`
- Migration of & Working on game
- Adding new Game design
- finish partial stage of network capsule

> Temp roadmap kinda list
- [x] `Gamepanel`  get working with the base Main class with proper `consoleLog`s
- [ ] Have to add this after commiting but need Loaders and Manual Classes to be added before anything related to big Fstreams
- [ ] if done with Panel running drawing `Map` is the goal
- [ ] Map is drawn rather than going for Sprites We get `Pacman` done
- [ ] Along with `EventListner`  & `EventHandler` (Game or Engine Idk I'm confused)
This is where the Pacman and roam around 
- [ ] Ghost? nah `SpriteManager` get all sf::Rect fill with Sprites 
- [ ] `Ghost` now ( Because codebase is huge for Ghost )
- [ ] `SoundManager` finishing Engine/'s half job
- [ ] Add `Menu` so we can get going on real **PacPac**
This is where I can make Pellets or Leaderboard for Offline but we need to work TcpSockets and Connection
because gameSense is validate on the Server::Room :) 
- [ ] Lots of `Server` Code to align with `Client`
- [ ] `Pellets` & `Powerups` can be between above or After Server is done 
for not adding overhead for us 
--- 




---
## Dev Log 13-02-2026
##### **Added**
- Added `Global` Constants for overall CONSTANTS

##### **Fixed** 
- Changes Window from Vector2u -> Unsigned Int building Vector2u
- Changes Window Obj to build from implicit Contructor and not Window.Create()

##### **Notes:** 
- In upcoming days I'll be adding Submodules I realise There will be Cross Platform Dependencies and Also SFML will break on Linux/Windows with Different Versions too
---


---
## Dev Log 10-02-2026
##### **Goals** 
- from `Game`
    - `Gamepanel` need to get finish 
    - `Map` adding it because of Level Simplicity 
    if above two are done work on `Pacman`
##### **Added**
- Added `Gamepanel` Class we can call it a Main Gameloop
- Added Console Logging funcnality 

##### **Notes:** 
-   Having too much TOO MUCH of Overhead for some Structure based Designing  
---




---
## Dev Log 07-02-2026

##### **Added**
- Base Structure of `client/`

##### **Notes:** 
- do `CMakeLists.txt` before start making builds
- starting Migrating codebase from Java to SFML C++
- `server/` is yet to be fully decided on either Full TS or C++/TS

##### **Plan** 
- start Migrating 
- design flow diagram for networking `server->client` & vice-versa
- for Migrating designing `gamepanel` & `entity/` would be better

---


