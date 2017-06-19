git clone https://github.com/vacrozet/gacp.git ~/.gacp
cd ~/.gacp
sleep 1
make
make clean
echo alias gacp='~/.gacp/gacp' >> ~/.zshrc
source ~/.zshrc
