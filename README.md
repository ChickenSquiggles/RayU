# RayU - WIP

**Hierarchical UI Abstraction for Raylib**

RayU is a UI abstraction layer built on top of Raylib that replaces direct pixel-based drawing with an object-driven layout system similar to Roblox. Instead of rendering directly to the window, you create UI objects that support:

- Parent–child relationships  
- Inherited size and position  
- Resolution-independent scaling  

Objects can define their size and position as either:

- Scale factors relative to their parent, or  
- Explicit pixel values when needed

This allows interfaces to remain **uniform across any monitor or window size**, without hard pixel dependencies.

This is mostly for my own learning so don't expect it to be the greatest project ever.

**If you do somehow stumble upon this, build however you use CMAKE, but my personal build workflow is 'cmake -S . -B build -G "MinGW Makefiles"' to start a build directory (one time thing), then 'cmake --build build' from then on.**