# SDCafiine (HBL version)

## What is SDCafiine
SDCafiine is a Homebrew Application for the Nintendo Wii U, that can be loaded with the [homebrew launcher](https://github.com/dimok789/homebrew_launcher). The main feature of this application is the **on-the-fly replacing of files**, which can be used used to loaded modified content from external media (**SD/USB**). It hooks into the file system functions of the WiiU. Whenever a file is accessed, SDCafiine checks if a (modified) version of it present on the SD/US device, and redirect the file operations if needed.

# Which games are supported
SDCafiine only supports games which already had access to the SD Card (for example Super Smash Bros. for Wii U), but you can extend the support to all games.
To achieve this load [mocha] (https://github.com/fre4kyc0de/mocha), which is a Custom Firmware with [libiosuhax](https://github.com/dimok789/libiosuhax) support, otherwise only SSBU is working. The built-in CFW of HAXCHI/CBHC is NOT supported. This allows support for any FAT32 device via [libfat](https://github.com/aliaspider/libfat). 

# Features
- On the fly file **replacing of game files**.
- Support for **replacing files from downloadable content**
- **Built in libiosuhax support** via mocha
- Supports loading files from **SD and USB** (FAT32)
- Support for **multiple modpacks** for as single game.

## How to use it

### Installation of SDCafiine
Like many other homebrew applications for the Wii U, it can't be installed. The application is only installed temporarily, and has to loaded again after each reboot (or entering the system settings). It is enough to copy the files on to the SDCard in a way it can be accessed by the [homebrew launcher](https://github.com/dimok789/homebrew_launcher), or simply download it from the [homebrew app store](https://www.wiiubru.com/appstore/#/)

Example path of the elf on the SD:
```
SD:/wiiu/apps/sdcafiine/sdcafiine.elf
```

### Starting SDCafiine

When the files are on the SDCard, use your prefered method to get into the [homebrew launcher](https://github.com/dimok789/homebrew_launcher) and start SDCafiine.
On success, the system menu should load. Now simply start any game and the mods should load.

### Installation of the mods
Before the mods can be loaded, they need to be copied to a SD or USB device. Since version 1.4 also USB devices (FAT32 only) are supported via libfat.
**In the following "root:/" is corresponding to the root of your SD/USB device**. The basic filepath structure is this:

```
root:/sdcafiine/[TITLEID]/[MODPACK]/content/  <-- for game files. Maps to /vol/content/
root:/sdcafiine/[TITLEID]/[MODPACK]/aoc/      <-- for downloadable content files. Maps to /vol/aocXXXXXXXX/
```
Replace the following:
- "[TITLEID]" need to be replaced the TitleID of the games that should be modded. A list of can be found [here](http://wiiubrew.org/w/index.php?title=Title_database#00050000:_eShop_and_disc_titles) (without the "-"). Example for SSBU "0005000010145000". Make sure to use the ID of the fullgame and not the update title ID. 
- "[MODPACK]" name of the modpack. This folder name can be everything but "content" or "aoc".

Example path for the EUR version of SuperSmashBros for Wii U:
```
root:/sdcafiine/0005000010145000/SpecialChars/content/  <-- for game files. Maps to /vol/content/
```

For replacing the file /vol/content/movie/intro.mp4, put a modified file into:
```
root:/sdcafiine/0005000010145000/SpecialChars/content/movie/intro.mp4
```

*NOTES: paths like "root:/sdcafiine/0005000010145000/content/" are still supported for compatibility, but **not recommended** *
### Handling multiple mod packs
SDCafiine supports multiple different mods for a single game on the same SDCard/USB. Each mod has an own subfolder.
Example:
```
sd:/sdcafiine/0005000010145000/ModPack1/content/  
sd:/sdcafiine/0005000010145000/ModPack2/content/  
usb:/sdcafiine/0005000010145000/ModPack3/content/ 
usb:/sdcafiine/0005000010145000/ModPack4/content/ 
```
When multiple folders are detected, you need to choose which one to use when starting the game. To swap to another mod, you need restart the game.

## Building
Make sure you download the complete repo, including the submodules:  

- git submodule update --init --recursive

For building you need: 
- [libfat](https://github.com/aliaspider/libfat/)
- [libiosuhax](https://github.com/dimok789/libiosuhax) (Build WITHOUT the WUT flag set.)

## Credits
HBL support, code rewrite and further improvements - Maschell  
minor improvements - Zarklord 
[inital SDCafiine creation](https://gbatemp.net/goto/post?id=5680630) - golden45  
Cafiine creation - chadderz (and MrBean35000vr ?)  
libfat - devkitPro team
