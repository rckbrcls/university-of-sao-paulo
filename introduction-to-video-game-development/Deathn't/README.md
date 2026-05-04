# Deathn't

> Status: archived Unity coursework project.

Deathn't is a Unity 2D game project from an introductory video game development course. The project includes C# gameplay scripts, scenes, sprites, animations, audio behavior, URP settings, and generated Unity folders.

## Scope

- Project type: Unity game project.
- Unity version: 2019.4.31f1, from `ProjectSettings/ProjectVersion.txt`.
- Main stack: Unity, C#, Universal Render Pipeline, 2D physics, animation, and scenes.
- Current status: archived study reference.

## Project Structure

| Path | Purpose |
| --- | --- |
| `Assets/Scenes/` | Unity scenes, including test scenes, menu scene, sketch levels, and actual levels. |
| `Assets/Scripts/` | Gameplay scripts for movement, possession, rewind, menus, switches, doors, animation, and collision checks. |
| `Assets/Sprites/` | Sprite and PSD assets. |
| `Assets/Animations/` | Animation clips and controllers. |
| `Assets/BGM.cs` | Background/death audio behavior. |
| `Assets/NextLevel.cs` | Scene progression trigger. |
| `Packages/manifest.json` | Unity package manifest. |
| `ProjectSettings/` | Unity project configuration. |
| `Library/`, `Logs/`, `Temp - Copia/` | Generated Unity artifacts committed in the archive. |

## Gameplay Systems

| System | Files |
| --- | --- |
| Movement | `Assets/Scripts/MovementSystem/AbstractMovement.cs`, `CharacterMovement.cs`, `PlataformMovement.cs`, `PlayerInput.cs`, `CollisionRegister.cs`. |
| AI and platforms | `GoombaAI.cs`, `PlataformAI.cs`, movement/collision helpers. |
| Possession | `PossessionPlayerComponent.cs`, `PossessionTarget.cs`. |
| Rewind | `RewindSystem/Recorder.cs`, `RewindSystem/RewindController.cs`, `RewindSystem/AlivePlayer.cs`. |
| Menus | `Menu/MainMenu.cs`, `Menu/PauseMenu.cs`, `Menu/OptionsMenu.cs`. |
| Doors and switches | `OneWayDoor/`, `Switches/PressurePlate.cs`, `Animations/DoorAnimationScript.cs`. |
| Animation helpers | `Animations/AnimationPlayer.cs`, `AnimationAbstract.cs`, `FlipGhost.cs`. |

## Opening the Project

Open `introduction-to-video-game-development/Deathn't/` in Unity 2019.4.31f1. Unity may regenerate `Library/`, `Logs/`, and temporary files when the project is opened.

## Package Notes

`Packages/manifest.json` references Unity packages such as:

- Universal Render Pipeline;
- Shader Graph;
- TextMeshPro;
- Timeline;
- Unity UI;
- 2D Sprite and Tilemap modules;
- editor integrations for VS Code, Visual Studio, and Rider.

## Limitations

- No automated Unity test workflow was identified.
- Generated Unity folders are committed as part of the historical archive.
- Some scripts preserve coursework-era names and commented-out prototypes.
