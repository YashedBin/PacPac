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
- [x] Have to add this after commiting but need Loaders and Manual Classes to be added before anything related to big Fstreams
- [x] if done with Panel running drawing `Map` is the goal
- [x] Map is drawn rather than going for Sprites We get `Pacman` done
- [ ] Along with `EventListner`  & `EventHandler` (Game or Engine Idk I'm confused)
This is where the Pacman and roam around 
- [x] Ghost? nah `SpriteManager` get all sf::Rect fill with Sprites 
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
## Dev Log 04-03-2026
##### **Added**
- Add `Engine::SpriteManager` with **Singleton** principal for static inconsistency 
- Add `Entity` abstract class
- Add `Entity::Pacman` with animation logic 
- Add `Direction` enum to use for all Entities
- Add `Core::Clog` for structured console logs 
- Add `ani_pacman_sheet.png`  **10x1** Asset SpriteSheet for Pacman
- Add `Core::Timer` with RAII based Timing & Formatting Time for `Core::Clog`
- Add Defined WindowSize & Map changes 

- Added `Engine::EntityManager` for better Entities managing and memory managing

##### **Changed/Refactored**
- Refactored `Global` Namespace to split into **PATH** , **CONFIG** & **CONST** for more clarity while writing
- Refactored `Drawable` Signature ( Changes Gamepanel, Entities Methods aswell ); 
- Refactored `Core::FileLoader` to have implicit loading via `load(path)` and Suffix Prefix checks
- Revamped `Entity<T>` to wrapper mechanics

- Entity `namespace` -> `Entities` namespace
- Updated build scripts for same reason
- **Sprites** from `Engine::SpriteManager` Now gets deleted before SM's obj becomes a Dangling pointer
- Gamepanel refactoring for common mistakes

##### **Config Changes**
- Configured  `**PreCompiledHeaders**` in Client/CMakeLists.txt
- Updated CMake for Cross Compilation TRY
- CMake fixes for MSVC & Directory references in build.sh

##### Removed Files
- Removed `consoleLog.cpp`, `consoleLog.hpp` 
- Removed `Entity<T>` completely -> Changing it into `Entity` abstract Class



##### **Plan** 
-  I DON"T HAVE ONE ANYMORE
- Cross compilation is falling off
- Linux binary is working great
I'll try my to get Windows Binary ready then Refactor the Code with Cross Codes and Adequate header ifdefs 
if worked? Docker or CICD actions are key to check if Window Binary gets compiled or not if not recheck the history to it again
if does Hope it's not a path error

- Doing 
Cross Compilation -> CICD or DOCKER -> REFACTORING -> Ghost -> Ghosts -> SoundManager etc

---


---
## Dev Log 26-02-2026
- missed a half week devLogs AND Progression

##### **Added**
- Add `Drawable` Abstract class (Need pure inheritance)
- Add `Entity<Position>` Template ( yea I rightaway wrote Position because
I'm about to Remove that WRAPPER)
- Add `entity.tpp`, `entity.hpp`, `drawable.hpp`, `core/timer.hpp`, & `core/consoeLog.hpp`
- Revamped `ConsoleLog` -> `CLog` a Semi-Complete Console Logger which will need
Scope, Logging Type, Msg/Task to Log in a little Pretty way
- Add `Timer` a Class which is RAII based Timer (obviously* counts overheads don't know why) 
- Revamped `Global` -> `PATH` + `CONFIG` + `CONST` for more Clarity and ...
- Add `Direction` Enums 

##### **Fixed** 
- Revamp/Fixed Compilation time (yea I searched for building cache but got Compile cache) 
in `client/CMakeLists.txt` with PreCompiledHeaders (PCH)

##### **Notes:** 
- `never try to use template with premature knowledge ever`
- enjoy beautiful log reading and adding `Core::CLog::Log(Three Parameters to Type)` to every meaning full scope

##### **Plan** 
- PLAN still is same as `20-02-26`'s DevLog 
- Change in Entity<T> to Entity Abstract Class 
---


---
## Dev Log 20-02-2026
##### **Added** 
- Added `Dear ImGui` --> `1.91.11`
- Added `ImGui-SFML` --> `v3`
- Added `Core::FileLoader`
without Audio, Sprite, Config Loading
- Added `Game::Map`
without Levels, and Util methods
- Added `assets/maps` & `assets/fonts` with 1 map.txt and 3 fonts
in which only 1 will be used

##### **Fixed** 
- Fixed Path issues for CMake Root and Client

##### **Notes:** 
- 
##### **Plan** 
- Plan for Map 
    - will be using .bin after I have done designing Map in the Editor
    - will be rendering it with Spritesheet After EventHandler designing
- Plan for Entities
    - Will be shifting to EntityTemplate ( tomorrow )
- Plan for CMake
    - will try to make it more natural to follow and also
    - TRY COMPILING ON MSVC AT LEAST!!
- Plan for EVENTS
    - EventListner ROUTER over SF:: 
    - EventHandler over Sf::Events
        - MouseHandler SS
        - KeyboardKHandler SS
        - or PacmanHandler ( which is Naive)
- Plan AFTER ENTITY_TEMPLATE
    - Pacman Template 
    - Bullet Template OR Ghost Template

and Get started on some ViewPort changes with ImGui too 
- TODAY NO MAP : ) 

---


---
## Dev Log 15-02-2026
##### **Added** 
- Add root CMakeLists.txt
- refactor miserly lines for `SFML 2.5` -> `SFML 3.0.2`
- Changes client/CMakeLists.txt 
---


---
## Dev Log 14-02-2026
##### **Added**
- Add Submodule `SFML` Locked to 3.0.2 
why 3.0.2 not 3.0.0 because of some CMake changes and etc 
So, it was more stable.
##### **Plan**

- [x] migrate the misely code into Ver 3 compatible ( just sf::Vector2 class if I remember correctly)
- [x] Global CMakeLists.txt and Client CMake
- [x] Change Build.sh / Build.bat
- [x] Add `ImGui-SFML` and Change builds and CMakeLists.txt
- [ ] Try a Window build run ( after Exams )
- [x] `FileLoader` & `Map` if everything is done

### Change of Plans for GUI

We won't be designing Templates with Fake buttons
We Will try to design the Aesthetics at it's best but 
` ImGui::ImGui ` Is here :) 
as there will be multiple things 
- Settings
- Menu
- Levels
- Themes
We ourselves should get a better Framework + there is a Debug screen in
ImGui for Data We want to look into that Personally!!

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


