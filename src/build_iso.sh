#!/usr/bin/env bash

set -euo pipefail

iso_name=kfs-1.iso

iso_content_dir="$HOME/iso"
iso_dist_dir="/dist"

MAKEFLAGS="-j$(nproc)"; export MAKEFLAGS

# shellcheck source=/dev/null
source "$HOME/.profile"

pushd "$HOME/kernel"
	make NAME=kfs-1.bin

	ls -a

	install -vD -m644 -t "$iso_content_dir/boot" kfs-1.bin
popd

grub-mkrescue -v -o "$iso_dist_dir/$iso_name" "$iso_content_dir"
