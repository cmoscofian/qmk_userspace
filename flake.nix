{
	description = "QMK keyboard firmware development environment";

	inputs =
	{
		nixpkgs =
		{
			url = "github:NixOS/nixpkgs/nixos-unstable";
		};
	};

	outputs = { self, nixpkgs, ... }:
	let
		system = "x86_64-linux";
		pkgs = nixpkgs.legacyPackages.${system};
	in with pkgs;
	{
		devShells.${system}.default = pkgs.mkShell
		{
			packages = with pkgs;
			[
				# QMK command-line interface
				qmk
				# Build tools
				gnumake
				python3
				dfu-util
				dos2unix

				# USB and serial debugging
				tio
				# Optional development utilities
				clang-tools
				pkg-config
			];
			shellHook = ''
				export PATH="${pkgs.pkgsCross.arm-embedded.buildPackages.gcc}:$PATH" '';
		};
	};
}
