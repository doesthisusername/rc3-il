## rc3-il
Quick patch for `NPEA00387` UYA to add some IL practice features:

- No autosave
- Ammo doesn't decrease
- Single-screen interplanetary loads
- Save/load position hotkey
- Instant savefile reloading

A timer is planned; I'll do it at some point.

### Usage
#### Hotkeys
- `L2+R2` held, then `L1` pressed: save position
- `L2+R2` held, then `R1` pressed: load position
- `L2+R2` held, then `R3` pressed: reload planet
- `L2+R2+L3` held, then `R3` pressed: reload the set-aside savefile
- `L2+R2+L3+Up` held, then `R3` pressed: set aside current savefile, then reload it

If no savefile has been set aside and you attempt to reload it, it will work like you also had `Up` held.

### Compiling and installing
0) Make sure your `make.sh` has LF line endings
1) Install `binutils-powerpc64-linux-gnu`. I use WSL. (e.g. `sudo apt install binutils-powerpc64-linux-gnu`)
2) Move a decrypted `EBOOT.BIN` of the game to this directory, and rename it to `EBOOT.ELF.bak`
3) `./make.sh` to compile/assemble the patches
4) `python3 apply.py` to apply the patches to the executable, saving to `EBOOT.ELF`
5) Resign `EBOOT.ELF` such that your platform of choice accepts it.
6) Replace `EBOOT.BIN` in the game