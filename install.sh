cd ~/documents/
git clone https://github.com/vacrozet/gacp.git
cd gacp
sleep 1
make
cp gacp pp
mv pp /usr/locale/bin/
make fclean