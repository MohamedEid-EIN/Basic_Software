#!/usr/bin/env python3
"""
Sync_cfg_Links.py

Creates and maintains a symbolic-link "configuration dashboard" under
01_Build_System/Cfg for easier configuration editing.

Key principles:
- Real C configuration files live in the software tree (06_Software)
- Real Make configuration files live in the toolchain tree (02_ToolChain)
- 01_Build_System/Cfg contains ONLY symbolic links
- Compilation and Make behavior are NOT affected
"""

import os
from pathlib import Path


def sync_software_cfgs(repo_root: Path) -> None:
    # ------------------------------------------------------------
    # Mirror software C configuration headers (FLAT VIEW)
    #
    # Real files:
    #   06_Software/**/<Module>/Cfg/*_Cfg.h
    #
    # Symbolic links created under:
    #   01_Build_System/Cfg/
    #
    # Result:
    #   01_Build_System/Cfg/GPIO_Cfg.h -> ../../06_Software/...
    #
    # Purpose:
    #   Flat, human-friendly view of all configuration headers
    #   without copying or mirroring directories.
    # ------------------------------------------------------------

    sw_root = repo_root / "06_Software"
    cfg_view_root = repo_root / "01_Build_System" / "Cfg"

    if not sw_root.exists():
        raise RuntimeError(f"Software root not found: {sw_root}")

    cfg_view_root.mkdir(parents=True, exist_ok=True)

    for cfg_file in sw_root.rglob("*_Cfg.h"):
        # Enforce expected structure:
        #   <Module>/Cfg/<Name>_Cfg.h
        if cfg_file.parent.name != "Cfg":
            continue

        dest_link = cfg_view_root / cfg_file.name

        # --------------------------------------------------------
        # If correct symlink already exists, do nothing
        # --------------------------------------------------------
        if dest_link.is_symlink():
            try:
                if dest_link.resolve() == cfg_file.resolve():
                    continue
            except FileNotFoundError:
                pass

        # Remove stale file or incorrect/broken symlink
        if dest_link.exists() or dest_link.is_symlink():
            dest_link.unlink()

        # --------------------------------------------------------
        # Create relative symbolic link (file-level only)
        # --------------------------------------------------------
        rel_target = os.path.relpath(cfg_file, cfg_view_root)
        dest_link.symlink_to(rel_target)

        print(f"[SW-CFG] Linked: {dest_link} -> {rel_target}")

def sync_linker_cfg(repo_root: Path) -> None:
    # ------------------------------------------------------------
    # Mirror linker configuration script
    #
    # Real file:
    #   06_Software/08_Platform/Linker/Cfg/Linker_Cfg.ld
    #
    # Symbolic link created under:
    #   01_Build_System/Cfg/Linker_Cfg.ld
    #
    # Purpose:
    #   Centralize MCU / memory configuration editing
    #   without touching linker structure or Make logic.
    # ------------------------------------------------------------

    src = (
        repo_root
        / "06_Software"
        / "08_Platform"
        / "Linker"
        / "Cfg"
        / "Linker_Cfg.ld"
    )

    dest_dir = repo_root / "01_Build_System" / "Cfg"
    dest_link = dest_dir / "Linker_Cfg.ld"

    if not src.exists():
        raise RuntimeError(f"Linker config not found: {src}")

    dest_dir.mkdir(parents=True, exist_ok=True)

    # If correct symlink already exists, do nothing
    if dest_link.is_symlink():
        try:
            if dest_link.resolve() == src.resolve():
                return
        except FileNotFoundError:
            pass

    # Remove stale file or incorrect symlink
    if dest_link.exists() or dest_link.is_symlink():
        dest_link.unlink()

    # Create relative symlink
    rel_target = os.path.relpath(src, dest_dir)
    dest_link.symlink_to(rel_target)

    print(f"[LINKER-CFG] Linked: {dest_link} -> {rel_target}")



def sync_toolchain_make_cfg(repo_root: Path) -> None:
    # ------------------------------------------------------------
    # Mirror toolchain Make configuration
    #
    # Real file:
    #   02_ToolChain/MakeFiles/Cfg/Make_Cfg.mk
    #
    # Symbolic link created under:
    #   01_Build_System/Cfg/Toolchain/Make_Cfg.mk
    #
    # Purpose:
    #   Allow editing all configuration (C + Make) from a single
    #   dashboard location without changing how Make is invoked.
    # ------------------------------------------------------------

    src = repo_root / "02_ToolChain" / "MakeFiles" / "Cfg" / "MakeFile_Cfg.mk"
    dest_dir = repo_root / "01_Build_System" / "Cfg"
    dest_link = dest_dir / "MakeFile_Cfg.mk"

    if not src.exists():
        raise RuntimeError(f"Toolchain Make config not found: {src}")

    dest_dir.mkdir(parents=True, exist_ok=True)

    # --------------------------------------------------------
    # If a correct symlink already exists, leave it untouched
    # --------------------------------------------------------
    if dest_link.is_symlink():
        try:
            if dest_link.resolve() == src.resolve():
                return
        except FileNotFoundError:
            pass

    # Remove stale file or incorrect/broken symlink
    if dest_link.exists() or dest_link.is_symlink():
        dest_link.unlink()

    # Create relative symbolic link
    rel_target = os.path.relpath(src, dest_dir)
    dest_link.symlink_to(rel_target)

    print(f"[MAKE-CFG] Linked: {dest_link} -> {rel_target}")


def main() -> None:
    repo_root = Path(__file__).resolve().parents[2]

    if not (repo_root / "01_Build_System").exists():
        raise RuntimeError("Invalid repository root detected")

    print(f"Repo root: {repo_root}")

    sync_software_cfgs(repo_root)
    sync_linker_cfg(repo_root)          # <-- THIS WAS MISSING
    sync_toolchain_make_cfg(repo_root)

    print("Configuration symlink synchronization complete.")


if __name__ == "__main__":
    main()
