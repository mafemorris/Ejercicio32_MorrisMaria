ejercicio.png : datos.txt ejercicio.py
	python ejercicio.py
	
datos.txt : ejercicio.x
	./ejercicio.x
	rm ejercicio.x
ejercicio.x : ejercicio1.cpp
	c++ ejercicio1.cpp -o ejercicio.x

clear : 
	ejercicio.png