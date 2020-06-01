-- EJERCICIO #1
SELECT codcli 'Codigo_Cliente', cliente.nombre 'Nombre', COUNT(*) 'Nº Facturas' FROM Clientes cliente
JOIN Facturas factura USING (codcli) WHERE 
EXTRACT( year FROM factura.fecha ) = EXTRACT( year from CURRENT_DATE ) - 1
GROUP BY codcli, cliente.nombre;

-- EJERCICIO #2
SELECT codfac 'Codigo factura', factura.fecha 'Fecha', SUM(linea_fac.precio * linea_fac.cant) 'Precio Total' FROM Facturas factura 
JOIN Lineas_fac linea_fac USING (codfac)
GROUP BY codfac, factura.fecha;

-- EJERCICIO #3
SELECT codven 'Codigo Vendedor', vendedor.nombre 'Nombre', SUM(linea_fac.precio*linea_fac.cant) 'Facturacion' FROM Vendedores vendedor
JOIN Facturas factura USING (codven)
JOIN Lineas_fac linea_fac USING (codfac)
WHERE EXTRACT(year FROM factura.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY codven, vendedor.nombre;

-- EJERCICIO #4
SELECT provincia.nombre 'Provincia', SUM(linea_fac.cant) 'Articulos Vendidos' FROM Provincias provincia
JOIN Pueblos pueblo USING (codpro)
JOIN Clientes cliente USING (codpue)
JOIN Facturas factura USING (codcli)
JOIN Lineas_fac linea_fac USING (codfac)
WHERE EXTRACT(year FROM factura.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY provincia.nombre;

-- EJERCICIO #5
SELECT DISTINCT codcli 'Codigo Cliente', cliente.nombre 'Nombre' FROM Clientes cliente
JOIN Pueblos pueblo1 ON cliente.codpue = pueblo1.codpue
JOIN Facturas facturas USING (codcli)
JOIN Vendedores vendedor USING (codven)
JOIN Pueblos pueblo2 ON vendedor.codpue = pueblo2.codpue
WHERE pueblo1.codpro <> pueblo2.codpro;

-- EJERCICIO #6
SELECT DISTINCT codcli 'Codigo Cliente', Clientes.nombre 'Nombre' FROM Lineas_fac 
JOIN Facturas USING (codfac)
JOIN Clientes USING (codcli)
JOIN Pueblos USING (codpue)
JOIN Provincias USING (codpro)
WHERE Provincias.nombre = 'Valencia'
GROUP BY codfac, codcli, Clientes.nombre
HAVING COUNT(*) >= 2;

-- EJERCICIO #7
SELECT codart 'Articulo', Articulos.descrip 'Descripcion' FROM Articulos
JOIN Lineas_fac USING (codart)
JOIN Facturas USING (codfac)
WHERE EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY codart, Articulos.descrip
HAVING COUNT(DISTINCT EXTRACT(month FROM Facturas.fecha)) > 1
AND MAX(EXTRACT(month FROM Facturas.fecha)) - MIN(EXTRACT(month FROM Facturas.fecha)) + 1 =
COUNT(DISTINCT EXTRACT(month FROM Facturas.fecha));

-- EJERCICIO 8
SELECT codcli 'Codigo Cliente', Clientes.nombre 'Nombre' FROM Pueblos
JOIN Clientes USING (codpue)
JOIN Facturas USING (codcli)
JOIN Lineas_fac USING (codfac)
JOIN Provincias USING (codpro)
WHERE Provincias.nombre = 'Barcelona' OR Provincias.nombre = 'Castellon'
GROUP BY codcli, Clientes.nombre
HAVING SUM( cant * precio ) > 6000.00;

-- EJERCICIO 9
SELECT MAX(SUM(Lineas_fac.cant * Lineas_fac.precio)) 'Facturacion Maxima' FROM Pueblos
JOIN Clientes USING (codpue)
JOIN Facturas USING (codcli)
JOIN Lineas_fac USING (codfac)
JOIN Provincias USING (codpro)
WHERE Provincias.nombre = 'Barcelona'
AND EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY codcli, EXTRACT(year FROM Facturas.fecha);

-- EJERCICIO 10
SELECT jefe.nombre 'Nombre Jefe', COUNT(*) 'Nº Vendedores' FROM Vendedores jefe
JOIN Vendedores vendedor ON vendedor.codjefe = jefe.codven
GROUP BY jefe.nombre;

-- EJERCICIO 11
SELECT Clientes.nombre 'Nombre Cliente', Pueblos.nombre 'Nombre Pueblo', COUNT(DISTINCT Lineas_fac.codart) 'Nombre Articulo' FROM Clientes
JOIN Pueblos USING (codpue)
JOIN Facturas USING (codcli)
JOIN Lineas_fac USING (codfac)
WHERE Pueblos.codpro = 'VA'
AND SUBSTR( Clientes.nombre, 1, 1 ) = SUBSTR( Pueblos.nombre, 1, 1 )
AND EXTRACT(month FROM Facturas.fecha) = 10 || EXTRACT(month FROM Facturas.fecha) = 11 || EXTRACT(month FROM Facturas.fecha) = 12
AND EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY codcli, Clientes.nombre, Pueblos.nombre
HAVING SUM(Lineas_fac.cant * Lineas_fac.precio) > 6000;

-- EJERCICIO 12
SELECT codart 'Codigo Articulo', Articulos.descrip 'Descripcion' FROM Articulos
JOIN Lineas_fac USING (codart)
JOIN Facturas USING (codfac)
JOIN Clientes USING (codcli)
JOIN Pueblos USING (codpue)
JOIN Provincias USING (codpro)
WHERE LENGTH( Articulos.descrip ) > 15
AND Provincias.nombre = 'Castellon'
AND EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
AND EXTRACT(month FROM Facturas.fecha) = 12
AND EXTRACT(day FROM Facturas.fecha) > 21
GROUP BY codart, Articulos.descrip
HAVING COUNT(DISTINCT codcli) > 5;

-- EJERCICIO 13
SELECT codpue 'Codigo Pueblo', Pueblos.nombre 'Nombre' FROM Pueblos
JOIN Provincias USING (codpro)
JOIN Clientes USING (codpue)
JOIN Facturas USING (codcli)
JOIN Lineas_fac USING (codfac)
WHERE UPPER(SUBSTR(Pueblos.nombre,1,1)) = UPPER(SUBSTR(Provincias.nombre,1,1))
AND EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
AND EXTRACT(month FROM Facturas.fecha) = 10 || EXTRACT(month FROM Facturas.fecha) = 11 || EXTRACT(month FROM Facturas.fecha) = 12
GROUP BY codpue, Pueblos.nombre
HAVING COUNT(DISTINCT codcli) > 3
AND SUM(Lineas_fac.cant) > 1000;

-- EJERCICIO 14
SELECT codven 'Codigo Vendedor', Vendedores.nombre 'Nombre', COUNT(DISTINCT codcli) 'Nº Cliente'FROM Vendedores
JOIN Pueblos pueblo1 ON Vendedores.codpue = pueblo1.codpue
JOIN Facturas USING (codven)
JOIN Clientes USING (codcli)
JOIN Pueblos pueblo2 ON Clientes.codpue = pueblo2.codpue
WHERE EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
AND EXTRACT(month FROM Facturas.fecha) > 21
AND (UPPER(Vendedores.nombre) LIKE '%EZ %' OR UPPER(Vendedores.nombre) LIKE '%EZ')
AND pueblo1.codpro = pueblo2.codpro
GROUP BY codven, Vendedores.nombre;

-- EJERCICIO 15
SELECT codpue 'Codigo Pueblo', pueblo1.nombre 'Nombre' FROM Pueblos pueblo1
JOIN Vendedores USING (codpue)
UNION ALL
SELECT codpue 'Codigo Pueblo', pueblo2.nombre 'Nombre' FROM Pueblos pueblo2
JOIN Clientes USING (codpue);

-- EJERCICIO 16
SELECT codpue 'Codigo Pueblo', pueblo1.nombre 'Nombre' FROM Pueblos pueblo1
JOIN Vendedores USING (codpue)
UNION
SELECT codpue 'Codigo Pueblo', pueblo2.nombre 'Nombre' FROM Pueblos pueblo2
JOIN Clientes USING (codpue);

-- EJERCICIO 17
SELECT DISTINCT Pueblos.codpue 'Codigo Pueblo', Pueblos.nombre 'Nombre' FROM Pueblos
INNER JOIN Vendedores ON Pueblos.codpue = Vendedores.codpue
INNER JOIN Clientes ON Pueblos.codpue = Clientes.codpue;

-- EJERCICIO 18
SELECT DISTINCT Pueblos.codpue 'Codigo Pueblo', Pueblos.nombre 'Nombre' FROM Pueblos
INNER JOIN Vendedores ON Pueblos.codpue = Vendedores.codpue
WHERE Pueblos.codpue NOT IN( 
SELECT Pueblos.codpue FROM Pueblos
INNER JOIN Clientes ON Pueblos.codpue = Clientes.codpue);

-- EJERCICIO 19
SELECT DISTINCT A.codart 'Codigo Articulo', A.descrip 'Descripcion' FROM Articulos A
WHERE A.codart NOT IN( 
SELECT B.codart FROM Articulos B
JOIN Lineas_fac USING (codart) 
JOIN Facturas USING (codfac)
WHERE EXTRACT(month FROM Facturas.fecha) = 1);

-- EJERCICIO 20
SELECT DISTINCT Articulos.codart 'Codigo Articulo' FROM Articulos
WHERE Articulos.stock > 20 AND Articulos.precio > 15 
NOT IN( 
SELECT Lineas_fac.codart FROM Lineas_fac, Facturas
WHERE Facturas.codfac = Lineas_fac.codfac
AND EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1);

-- EJERCICIO 21
SELECT DISTINCT Vendedores.nombre 'Nombre Vendedor'  FROM Vendedores
INNER JOIN Clientes ON Vendedores.nombre = Clientes.nombre;

-- EJERCICIO 22
SELECT DISTINCT Articulos.codart 'Codigo Articulo' FROM Articulos
INNER JOIN Lineas_fac ON Articulos.codart = Lineas_fac.codart
WHERE Articulos.stock < Articulos.stock_min * 3
GROUP BY Lineas_fac.codart
HAVING SUM(Lineas_fac.cant) > 10

-- EJERCICIO 23
SELECT DATE_FORMAT(SYSDATE(), '%Y') || DATE_FORMAT(SYSDATE(), '%m') 'Codigo', DATE_FORMAT(SYSDATE(), '%Y') 'Anyo', DATE_FORMAT(SYSDATE(), '%m')'Mes', SUM( Lineas_fac.cant * Lineas_fac.precio ) 'Facturacion' FROM Facturas
JOIN Lineas_fac USING (codfac)
GROUP BY DATE_FORMAT(SYSDATE(), '%Y'), DATE_FORMAT(SYSDATE(), '%m')

-- EJERCICIO 24
SELECT A.codpro 'Codigo Provincia', A.nombre 'Nombre' FROM Provincias A
WHERE A.codpro NOT IN(
SELECT(B.codpro, B.nombre FROM Provincias B
JOIN Pueblos USING (codpro)
JOIN Vendedores USING (codpue)
JOIN Facturas USING (codven)
WHERE EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1));

-- EJERCICIO 25
SELECT DISTINCT Articulos.codart 'Codigo Articulo', Articulos.descrip 'Descripcion' FROM Articulos
JOIN Lineas_fac USING (codart)
WHERE Articulos.codart NOT IN(
SELECT Articulos.codart FROM Articulos
JOIN Lineas_fac USING (codart)
JOIN Facturas USING (codfac)
JOIN Clientes USING (codcli)
JOIN Pueblos USING (codpue)
JOIN Provincias USING (codpro)
WHERE Provincias.nombre = 'Castellon'); 

-- EJERCICIO 26
SELECT Provincias.Nombre 'Nombre Provincia', COUNT(*) 'N Facturas' FROM Provincias
JOIN Pueblos USING (codpro)
JOIN Clientes USING (codpue)
JOIN Facturas USING (codcli)
WHERE EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1
GROUP BY Provincias.codpro
UNION(
SELECT Provincias.nombre, 0 FROM Provincias
WHERE Provincias.codpro NOT IN(
SELECT Provincias.codpro FROM Provincias
JOIN Pueblos USING (codpro)
JOIN Clientes USING (codpue)
JOIN Facturas USING (codcli)
WHERE EXTRACT(year FROM Facturas.fecha) = EXTRACT(year FROM CURRENT_DATE) - 1));











