# samp-walking-styles

[![sampctl](https://img.shields.io/badge/mergevos-samp--walking--styles-2f2f2f.svg?style=for-the-badge)](https://github.com/Mergevos/samp-walking-styles)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install Mergevos/samp-walking-styles
```

Include in your code and begin using the library:

```pawn
#include <walking-styles>
```

## Usage

If you've had included this into your script/gamemode etc... Start by using a simple function  
```pawn
SetPlayerWalkingStyle(const playerid, const style);
```
This is going to set you some of walking styles below 
```pawn
enum {
	WALKING_STYLE_DEFAULT = 0,
	WALKING_STYLE_NORMAL,
	WALKING_STYLE_PED,
	WALKING_STYLE_GANGSTA,
	WALKING_STYLE_GANGSTA2,
	WALKING_STYLE_OLD,
	WALKING_STYLE_FAT_OLD,
	WALKING_STYLE_FAT,
	WALKING_STYLE_WOMANOLD,
	WALKING_STYLE_WOMANFATOLD,
	WALKING_STYLE_SHUFFLE,
	WALKING_STYLE_LADY,
	WALKING_STYLE_LADY2,
	WALKING_STYLE_WHORE,
	WALKING_STYLE_WHORE2,
	WALKING_STYLE_DRUNK,
	WALKING_STYLE_BLIND
};
```
And there is 
```pawn
GetPlayerWalkingStyle(const playerid);
```
This will return you the player's walking style.

*Note*: If you've set the player's walking style, to activate it, firstly press _W_ then _left alt_ key.

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, firstly configure pawn.json then simply run the package:

```bash
sampctl package run
```
