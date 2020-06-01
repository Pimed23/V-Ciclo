-- INSERTAR PROVINCIAS
CALL insertarProvincia('AQ','Arequipa');
CALL insertarProvincia('AL','Alicante');
CALL insertarProvincia('BA','Barcelona');
CALL insertarProvincia('CA','Castellon');
CALL insertarProvincia('GE','Gerona');
CALL insertarProvincia('VA','Valencia');

-- INSERTAR PUEBLOS
CALL insertarPueblo('AQP00','Arequipa','AQ');
CALL insertarPueblo('ALI00','Guadalest','AL');
CALL insertarPueblo('ALI01','Calpe','AL');
CALL insertarPueblo('BAR00','Tavertet','BA');
CALL insertarPueblo('BAR01','Cardona','BA');
CALL insertarPueblo('GER00','Monells','GE');
CALL insertarPueblo('GER01','Santa Pau','GE');
CALL insertarPueblo('VAL00','Sagunto','VA');
CALL insertarPueblo('VAL01','Miramar','VA');

-- INSERTAR CLIENTES
CALL insertarCliente(10000,'Nadinne','Av. Jesus #2008','40000','AQP00');
CALL insertarCliente(10001,'Lucia','Av. Flores #205','40001','ALI00');
CALL insertarCliente(10002,'Marina','Calle Roma #125','40001','ALI00');
CALL insertarCliente(10003,'Jose','Urb. Casa Blanca A-7','40002','ALI01');
CALL insertarCliente(10004,'Pedro','Av. Paris #1562','40002','ALI01');
CALL insertarCliente(10005,'Gabriel','Calle Segovia #560','40003','BAR00');
CALL insertarCliente(10006,'Samantha','Urb. Electrica F-15','40003','BAR00');
CALL insertarCliente(10007,'Carla','Av. Venecia #645','40004','BAR01');
CALL insertarCliente(10008,'Carmen','Calle Azul #456','40004','BAR01');
CALL insertarCliente(10009,'Mario','Urb. Colon C-15','40005','GER00');
CALL insertarCliente(10010,'David','Av. Girasoles #935','40005','GER00');
CALL insertarCliente(10011,'Luis','Calle Libertad #125','40006','GER01');
CALL insertarCliente(10012,'Vicente','Urb. Independencia H-9','40006','GER01');
CALL insertarCliente(10013,'Silvia','Av. Colonial #247','40007','VAL00');
CALL insertarCliente(10014,'Javier','Calle Tokio #842','40007','VAL00');
CALL insertarCliente(10015,'Stephanie','Urb. Monterrico B-2','40008','VAL01');
CALL insertarCliente(10016,'Carlos','Av. Ejercito #429','40008','VAL01');

-- INSERTAR VENDEDORES
CALL insertarVendedor(10000,'Brian','Urb. Manco Capac F-34','40000','AQP00',10000);
CALL insertarVendedor(10001,'Liza','Av. Albacete #1253 ','40001','ALI00',10000);
CALL insertarVendedor(10002,'Charlie','Calle Alcala #152','40001','ALI00',10001);
CALL insertarVendedor(10003,'Joel','Urb. Daganzo E-15','40002','ALI01',10001);
CALL insertarVendedor(10004,'Juan','Av. Algeciras #2145','40002','ALI01',10001);
CALL insertarVendedor(10005,'Roberto','Calle Larios #451','40003','BAR00',10000);
CALL insertarVendedor(10006,'Paco','Urb. Fragua S-4','40003','BAR00',10005);
CALL insertarVendedor(10007,'Bruno','Av. Lerida #246','40004','BAR01',10005);
CALL insertarVendedor(10008,'Hugo','Calle Betis #748','40004','BAR01',10005);
CALL insertarVendedor(10009,'Magda','Urb. Fuenfria K-3','40005','GER00',10000);
CALL insertarVendedor(10010,'Rosa','Av. Sevilla #1211','40005','GER00',10009);
CALL insertarVendedor(10011,'Florencia','Calle Rabat #321 ','40006','GER01',10009);
CALL insertarVendedor(10012,'Susan','Urb. Raimundo Lulio G-2','40006','GER01',10009);
CALL insertarVendedor(10013,'Cecilia','Av. Nenufares #1245','40007','VAL00',10000);
CALL insertarVendedor(10014,'Karina','Calle Zafiro #653','40007','VAL00',10013);
CALL insertarVendedor(10015,'Lourdes','Urb. Zaragoza P-23','40008','VAL01',10013);
CALL insertarVendedor(10016,'Scarlet','Av. Cid #1954','40008','VAL01',10013);

-- INSERTAR ARTICULOS
CALL insertarArticulo('LICUAD00','Licuadora',299.99,25,10);
CALL insertarArticulo('COCINA00','Cocina',549.99,20,5);
CALL insertarArticulo('REFRIG00','Refrigerador',979.99,20,5);
CALL insertarArticulo('BATIDO00','Batidora',40.50,40,15);
CALL insertarArticulo('LAVADO00','Lavadora',849.00,20,5);
CALL insertarArticulo('SECADO00','Secadora',699.19,25,5);
CALL insertarArticulo('CAFETE00','Cafetera',70.99,40,15);
CALL insertarArticulo('EXTRAC00','Extractor',399.20,35,10);
CALL insertarArticulo('PICADO00','Picadora',169.90,35,10);

-- INSERTAR FACTURAS
CALL insertarFactura(100000,'2019-01-01',10000,10000,18,NULL);
CALL insertarFactura(100001,'2019-01-05',10001,10001,18,NULL);
CALL insertarFactura(100002,'2019-01-15',10002,10001,18,NULL);
CALL insertarFactura(100003,'2019-01-30',10002,10002,18,NULL);
CALL insertarFactura(100004,'2019-02-02',10002,10002,18,NULL);
CALL insertarFactura(100005,'2019-02-12',10003,10002,18,NULL);
CALL insertarFactura(100006,'2019-03-04',10003,10003,18,NULL);
CALL insertarFactura(100007,'2019-03-14',10004,10003,18,NULL);
CALL insertarFactura(100008,'2019-03-25',10004,10004,18,NULL);
CALL insertarFactura(100009,'2019-04-24',10005,10005,18,NULL);
CALL insertarFactura(100010,'2019-04-30',10006,10005,18,NULL);
CALL insertarFactura(100011,'2019-05-02',10006,10005,18,NULL);
CALL insertarFactura(100012,'2019-05-10',10006,10005,18,NULL);
CALL insertarFactura(100013,'2019-05-15',10007,10006,18,NULL);
CALL insertarFactura(100014,'2019-05-22',10008,10007,18,NULL);
CALL insertarFactura(100015,'2019-05-27',10008,10008,18,NULL);
CALL insertarFactura(100016,'2019-06-06',10009,10008,18,NULL);
CALL insertarFactura(100017,'2019-06-07',10009,10009,18,NULL);
CALL insertarFactura(100018,'2019-06-16',10009,10009,18,NULL);
CALL insertarFactura(100019,'2019-06-24',10010,10009,18,NULL);
CALL insertarFactura(100020,'2019-07-06',10010,10010,18,NULL);
CALL insertarFactura(100021,'2019-07-14',10011,10011,18,NULL);
CALL insertarFactura(100022,'2019-08-03',10011,10011,18,NULL);
CALL insertarFactura(100023,'2019-08-26',10011,10012,18,NULL);
CALL insertarFactura(100024,'2019-08-28',10012,10013,18,NULL);
CALL insertarFactura(100025,'2019-09-04',10012,10013,18,NULL);
CALL insertarFactura(100026,'2019-09-09',10013,10013,18,NULL);
CALL insertarFactura(100027,'2019-10-12',10013,10014,18,NULL);
CALL insertarFactura(100028,'2019-10-29',10014,10014,18,NULL);
CALL insertarFactura(100029,'2019-11-10',10014,10015,18,NULL);
CALL insertarFactura(100030,'2019-11-17',10015,10015,18,NULL);
CALL insertarFactura(100031,'2019-11-18',10016,10015,18,NULL);
CALL insertarFactura(100032,'2019-12-02',10016,10015,18,NULL);
CALL insertarFactura(100033,'2019-12-10',10016,10016,18,NULL);

-- INSERTAR LINEAS DE FACTURACION
CALL insertarLineaFac(100000,1,2,'LICUAD00',NULL);
CALL insertarLineaFac(100001,1,3,'LICUAD00',NULL);
CALL insertarLineaFac(100001,2,1,'COCINA00',NULL);
CALL insertarLineaFac(100002,1,2,'REFRIG00',NULL);
CALL insertarLineaFac(100003,1,3,'LICUAD00',NULL);
CALL insertarLineaFac(100004,1,2,'COCINA00',NULL);
CALL insertarLineaFac(100004,2,3,'REFRIG00',NULL);
CALL insertarLineaFac(100004,3,4,'BATIDO00',NULL);
CALL insertarLineaFac(100005,1,1,'CAFETE00',NULL);
CALL insertarLineaFac(100006,1,2,'EXTRAC00',NULL);
CALL insertarLineaFac(100007,1,1,'PICADO00',NULL);
CALL insertarLineaFac(100008,1,2,'CAFETE00',NULL);
CALL insertarLineaFac(100008,2,2,'LAVADO00',NULL);
CALL insertarLineaFac(100009,1,9,'REFRIG00',NULL);
CALL insertarLineaFac(100010,1,1,'COCINA00',NULL);
CALL insertarLineaFac(100011,1,1,'REFRIG00',NULL);
CALL insertarLineaFac(100011,2,2,'LAVADO00',NULL);
CALL insertarLineaFac(100012,1,1,'LAVADO00',NULL);
CALL insertarLineaFac(100013,1,4,'COCINA00',NULL);
CALL insertarLineaFac(100014,1,1,'PICADO00',NULL);
CALL insertarLineaFac(100014,2,2,'REFRIG00',NULL);
CALL insertarLineaFac(100015,1,3,'PICADO00',NULL);
CALL insertarLineaFac(100015,2,2,'REFRIG00',NULL);
CALL insertarLineaFac(100016,1,1,'EXTRAC00',NULL);
CALL insertarLineaFac(100017,1,2,'LAVADO00',NULL);
CALL insertarLineaFac(100018,1,3,'LICUAD00',NULL);
CALL insertarLineaFac(100019,1,2,'REFRIG00',NULL);
CALL insertarLineaFac(100020,1,5,'COCINA00',NULL);
CALL insertarLineaFac(100020,2,6,'CAFETE00',NULL);
CALL insertarLineaFac(100020,3,2,'SECADO00',NULL);
CALL insertarLineaFac(100021,1,2,'LAVADO00',NULL);
CALL insertarLineaFac(100022,1,1,'EXTRAC00',NULL);
CALL insertarLineaFac(100023,1,1,'PICADO00',NULL);
CALL insertarLineaFac(100024,1,2,'REFRIG00',NULL);
CALL insertarLineaFac(100024,2,2,'COCINA00',NULL);
CALL insertarLineaFac(100025,1,5,'REFRIG00',NULL);
CALL insertarLineaFac(100026,1,1,'SECADO00',NULL);
CALL insertarLineaFac(100027,1,2,'PICADO00',NULL);
CALL insertarLineaFac(100028,1,1,'SECADO00',NULL);
CALL insertarLineaFac(100029,1,1,'LICUAD00',NULL);
CALL insertarLineaFac(100030,1,1,'SECADO00',NULL);
CALL insertarLineaFac(100030,2,1,'COCINA00',NULL);
CALL insertarLineaFac(100031,1,1,'REFRIG00',NULL);
CALL insertarLineaFac(100032,1,2,'PICADO00',NULL);
CALL insertarLineaFac(100033,1,1,'EXTRAC00',NULL);
CALL insertarLineaFac(100033,2,1,'LICUAD00',NULL);


