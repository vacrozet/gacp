cd ~/Documents/
git clone https://github.com/vacrozet/gacp.git
cd gacp
sleep 1
make
make clean
echo alias pp='~/Documents/gacp/gacp' >> ~/.zshrc
