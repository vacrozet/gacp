cd ~/documents/
git clone https://github.com/vacrozet/gacp.git
cd gacp
sleep 1
make
mv gacp pp
mv ~/Documents/gacp/pp /usr/local/bin/
make fclean