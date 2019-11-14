grafica.png : data1.dat data2.dat rk.x
	python graficar.py
data2.dat : rk.x
	./rk.x 1 > data2.dat
data1.dat : rk.x
	./rk.x 0 > data1.dat
rk.x : rk.cpp
	c++ rk.cpp -o rk.x