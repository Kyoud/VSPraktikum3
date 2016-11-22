struct valuesStruct {
	1: string unixtime,
	2: i64 t0,
	3: i64 t1,
	4: i64 t2,
	5: i64 t3	
}

service timeserver {
    void ping(),
    valuesStruct time()
}


