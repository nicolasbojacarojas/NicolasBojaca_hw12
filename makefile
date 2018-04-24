snapshots.png: NB_graph.py advection.txt
	python3 NB_graph.py
advection.txt: NB_advection.cpp
	c++ NB_advection.cpp -o advection
	./advection > advection.txt
