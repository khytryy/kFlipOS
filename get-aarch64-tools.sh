cd ~
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.3.rel1/binrel/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz

echo "Extracting the toolchain..."
tar -xf arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf.tar.xz

echo -e "export PATH=~/arm-gnu-toolchain-14.3.rel1-x86_64-aarch64-none-elf/bin:$PATH\n" >> ~/.bashrc
echo "The toolchain is installed. Please run source ~/.bashrc or restart your terminal."