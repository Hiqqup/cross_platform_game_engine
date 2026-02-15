{
  description = "glfw dependencies";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.11";
  };

 outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          pkg-config
          libGL
          vulkan-loader
          xorg.libXrandr
          xorg.libXinerama
          xorg.libXcursor
          xorg.libX11
          xorg.libXi
          xorg.libXext
          xorg.libXxf86vm
          wayland
          wayland-scanner
          wayland-protocols
          libxkbcommon
          libdecor
          cmake
          gcc13
          emscripten
          chromium
        ];
        shellHook = ''
          mkdir -p $PWD/emcache
          export EM_CACHE="$PWD/emcache"
          '';
      };
    };
}
