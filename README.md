# [CSWM](https://forums.alliedmods.net/showthread.php?t=308229)

Counter-Strike Weapon Mod :gun:

<br><br>

- Infinite amount of weapons
- Custom ammo types
- Presets for Attack2
- Forwards and flags for custom weapon
- For any Mod (ZP, BB, Classic...)

# [Wiki](https://github.com/BeqaGurgenidze/CSWM/wiki)
<br>

# Known Issues
- Crosshair isn't working properly.　=> Can't fix it. it is client logic.
<br><br><br><br>

# [Linux]
Since libgcc_s.so.1 and libstdc++.so.6 bundled with HLDS for Linux are too old, install the latest GCC and place symbolic links to the respective libraries.

1. install gcc over than 11.3.1
2. command execute.

+ cd /[your hlds directory]/

+ mv libgcc_s.so.1 libgcc_s.so.1.bk
+ mv libstdc++.so.6 libstdc++.so.6.bk

+ ln -s /usr/lib/libgcc_s.so.1 libgcc_s.so.1
+ ln -s /usr/lib/libstdc++.so.6 libstdc++.so.6

