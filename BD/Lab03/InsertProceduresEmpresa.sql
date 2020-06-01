USE Empresa;
DROP PROCEDURE IF EXISTS insertarProvincia;
DELIMITER $$
CREATE PROCEDURE insertarProvincia(
	IN _codpro VARCHAR(2),
	IN _nombre VARCHAR(30))
BEGIN
	INSERT INTO Provincias(codpro, nombre) 
	VALUES(_codpro, _nombre);
END$$

DROP PROCEDURE IF EXISTS insertarPueblo;
DELIMITER $$
CREATE PROCEDURE insertarPueblo(
	IN _codpue VARCHAR(5),
	IN _nombre VARCHAR(40),
	IN _codpro VARCHAR(2))
BEGIN
	INSERT INTO Pueblos(codpue, nombre, codpro) 
	VALUES(_codpue, _nombre, _codpro);
END$$

DROP PROCEDURE IF EXISTS insertarCliente;
DELIMITER $$
CREATE PROCEDURE insertarCliente(
	IN _codcli DECIMAL(5,0) UNSIGNED,
	IN _nombre VARCHAR(50),
	IN _direccion VARCHAR(50),
	IN _codpostal VARCHAR(5),
	IN _codpue VARCHAR(5))
BEGIN
	INSERT INTO Clientes(codcli, nombre, direccion, codpostal, codpue) 
	VALUES(_codcli, _nombre, _direccion, _codpostal, _codpue);
END$$

DROP PROCEDURE IF EXISTS insertarVendedor;
DELIMITER $$
CREATE PROCEDURE insertarVendedor(
	IN _codven DECIMAL(5,0) UNSIGNED,
	IN _nombre VARCHAR(50),
	IN _direccion VARCHAR(50),
	IN _codpostal VARCHAR(6),
	IN _codpue VARCHAR(5),
	IN _codjefe DECIMAL(5,0) UNSIGNED)
BEGIN
	INSERT INTO Vendedores(codven, nombre, direccion, codpostal, codpue, codjefe) 
	VALUES(_codven, _nombre, _direccion, _codpostal, _codpue, _codjefe);
END$$

DROP PROCEDURE IF EXISTS insertarArticulo;
DELIMITER $$
CREATE PROCEDURE insertarArticulo(
	IN _codart VARCHAR(8),
	IN _descrip VARCHAR(40),
	IN _precio DECIMAL(9,2) UNSIGNED,
	IN _stock INT UNSIGNED,
	IN _stock_min INT UNSIGNED)
BEGIN
	INSERT INTO Articulos(codart, descrip, precio, stock, stock_min) 
	VALUES(_codart, _descrip, _precio, _stock, _stock_min);
END$$

DROP PROCEDURE IF EXISTS insertarFactura;
DELIMITER $$
CREATE PROCEDURE insertarFactura(
	IN _codfac DECIMAL(6,0) UNSIGNED,
	IN _fecha DATE,
	IN _codcli DECIMAL(5,0) UNSIGNED,
	IN _codven DECIMAL(5,0) UNSIGNED,
	IN _iva SMALLINT UNSIGNED,
	IN _dto SMALLINT)
BEGIN
	INSERT INTO Facturas(codfac, fecha, codcli, codven, iva, dto) 
	VALUES(_codfac, _fecha, _codcli, _codven, _iva, _dto);
END$$

DROP PROCEDURE IF EXISTS insertarLineaFac;
DELIMITER $$
CREATE PROCEDURE insertarLineaFac(
	IN _codfac DECIMAL(6,0) UNSIGNED,
	IN _linea SMALLINT UNSIGNED,
	IN _cant INT UNSIGNED,
	IN _codart VARCHAR(8),
	IN _dto SMALLINT)
BEGIN
	DECLARE _precio DECIMAL(9,2) UNSIGNED;
	SET _precio = (SELECT precio FROM Articulos WHERE codart = _codart);
	INSERT INTO Lineas_fac(codfac, linea, cant, codart, precio, dto) 
	VALUES(_codfac, _linea, _cant, _codart, _precio, _dto);
END$$

