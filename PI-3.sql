drop database pi3;

create database pi3;

USE pi3;
CREATE TABLE usuario(
id integer not null primary key auto_increment,
nome  varchar (50) not null,
login varchar (20) not null,
senha varchar (20) not null,
nivel integer not null);

CREATE TABLE cargo(
id integer not null primary key auto_increment,
nome varchar (30) not null,
salario numeric (6.2) not null);

CREATE TABLE periodo(
id integer not null primary key auto_increment,
datainicial date not null,
datafinal date not null);

CREATE TABLE funcionario(
id integer not null primary key auto_increment,
nome varchar (100) not null,
telefone varchar (15) not null,
endereco varchar (200) not null,
bairro varchar (30) not null,
cidade varchar (30) not null,
uf varchar (3) not null);

CREATE TABLE controlehorasaux(
data1 date not null,
tipodia integer not null,
hrsentrada1 time null,
hrssaida1 time null,
hrsentrada2 time null,
hrssaida2 time null,
hrstrabalhadas time null,
hrs100 time null,
hrs50 time null,
adcnoturno time null,
id_tab_periodo integer not null,
id_tab_funcionario integer not null,
constraint fka_controlehoras_periodo foreign key (id_tab_periodo) references periodo(id),
constraint fka_controlehoras_funcionario foreign key (id_tab_funcionario) references funcionario(id),
primary key (data1,id_tab_periodo, id_tab_funcionario));

CREATE TABLE controlehoras(
data1 date not null,
tipodia integer not null,
hrsentrada1 time null,
hrssaida1 time null,
hrsentrada2 time null,
hrssaida2 time null,
hrstrabalhadas time null,
hrs100 time null,
hrs50 time null,
adcnoturno time null,
id_tab_periodo integer not null,
id_tab_funcionario integer not null,
constraint fk_controlehoras_periodo foreign key (id_tab_periodo) references periodo(id),
constraint fk_controlehoras_funcionario foreign key (id_tab_funcionario) references funcionario(id),
primary key (data1,id_tab_periodo, id_tab_funcionario));

DELIMITER $$
CREATE TRIGGER trg_lanca_horas
AFTER INSERT ON controlehorasaux FOR EACH ROW
BEGIN
	INSERT INTO controlehoras (data1,tipodia,hrsentrada1,hrssaida1,hrsentrada2,hrssaida2,hrstrabalhadas,hrs100,hrs50,adcnoturno,id_tab_periodo,id_tab_funcionario)
    VALUES(NEW.data1,NEW.tipodia,NEW.hrsentrada1,NEW.hrssaida1,NEW.hrsentrada2,NEW.hrssaida2,NEW.hrstrabalhadas,NEW.hrs100,NEW.hrs50,NEW.adcnoturno,NEW.id_tab_periodo,NEW.id_tab_funcionario);
    IF NEW.tipodia = 1 THEN
		UPDATE controlehoras SET hrstrabalhadas = (NEW.hrssaida1 - NEW.hrsentrada1) + (NEW.hrssaida2 - NEW.hrsentrada2) WHERE data1 = NEW.data1 AND id_tab_funcionario = NEW.id_tab_funcionario AND id_tab_periodo = NEW.id_tab_periodo;
    ELSEIF NEW.tipodia = 2 THEN
		UPDATE controlehoras SET hrs50 = (NEW.hrssaida1 - NEW.hrsentrada1) + (NEW.hrssaida2 - NEW.hrsentrada2) WHERE data1 = NEW.data1 AND id_tab_funcionario = NEW.id_tab_funcionario AND id_tab_periodo = NEW.id_tab_periodo;
	ELSEIF NEW.tipodia = 3 THEN
		UPDATE controlehoras SET hrs100 = (NEW.hrssaida1 - NEW.hrsentrada1) + (NEW.hrssaida2 - NEW.hrsentrada2) WHERE data1 = NEW.data1 AND id_tab_funcionario = NEW.id_tab_funcionario AND id_tab_periodo = NEW.id_tab_periodo;
    END IF;
END; $$
DELIMITER ;

CREATE TABLE gasto(
datagasto date not null,
descontos numeric (6.2) not null,
id_tab_funcionario integer not null,
constraint fk_gasto_funcionario foreign key (id_tab_funcionario) references funcionario(id),
primary key (datagasto,id_tab_funcionario));

CREATE TABLE ocupa(
datainicial datetime not null,
datafinal datetime,
id_tab_funcionario integer not null,
id_tab_cargo integer not null,
adicional numeric (6.2),
constraint fk_ocupa_funcionario foreign key (id_tab_funcionario) references funcionario(id),
constraint fk_ocupa_cargo foreign key (id_tab_cargo) references cargo(id),
primary key (datainicial,id_tab_funcionario,id_tab_cargo));

INSERT INTO usuario VALUES (null,'LOURIVAL VICENTE DA SILVA JUNIOR','LOURIVAL','123456789',1);
INSERT INTO usuario VALUES (null,'ROMILDO ALVES DE SOUZA JUNIOR','ROMILDO','123456789',2);
INSERT INTO usuario VALUES (null,'MAIDSON MATEUS SILVA SOUZA','MAIDSON','123456789',3);

INSERT INTO periodo VALUES (null,20190101,20190131);
INSERT INTO periodo VALUES (null,20190201,20190228);
INSERT INTO periodo VALUES (null,20190301,20190331);
INSERT INTO periodo VALUES (null,20190401,20190430);
INSERT INTO periodo VALUES (null,20190501,20190531);
INSERT INTO periodo VALUES (null,20190601,20190630);
INSERT INTO periodo VALUES (null,20190701,20190731);
INSERT INTO periodo VALUES (null,20190801,20190831);
INSERT INTO periodo VALUES (null,20190901,20190930);
INSERT INTO periodo VALUES (null,20191001,20191031);
INSERT INTO periodo VALUES (null,20191101,20191130);
INSERT INTO periodo VALUES (null,20191201,20191231);

INSERT INTO funcionario VALUES (NULL,'LOURIVAL JUNIOR',36368239,'RUA ANGICO 88','FLORESTA','JATAI','GO');
INSERT INTO funcionario VALUES (null,'ROMILDO JUNIOR',36361400,'RUA MINAS 101','FATIMA','JATAI','GO');
INSERT INTO funcionario VALUES (null,'MAIDSON MATEUS',36361300,'RUA ROTA 123','ANTENA','JATAI','GO');

INSERT INTO cargo VALUES (null,'ELETRICISTA',2300.00);
INSERT INTO cargo VALUES (null,'ANALISTA RH',2000.00);
INSERT INTO cargo VALUES (null,'SERVICOGERAIS',2100.00);

INSERT INTO ocupa VALUES (20190101,20190130,01,01,500.00);
INSERT INTO ocupa VALUES (20190101,20190130,02,02,500.00);
INSERT INTO ocupa VALUES (20190101,20190130,03,03,600.00);

INSERT INTO controlehorasaux VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,null,01,01);
INSERT INTO controlehorasaux VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,null,01,01);
INSERT INTO controlehorasaux VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,null,01,01);
INSERT INTO controlehorasaux VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,null,01,01);
INSERT INTO controlehorasaux VALUES (20190105,'2',080000,110000,123000,173000,null,null,null,null,01,01);

INSERT INTO controlehorasaux VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,null,01,02);
INSERT INTO controlehorasaux VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,null,01,02);
INSERT INTO controlehorasaux VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,null,01,02);
INSERT INTO controlehorasaux VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,null,01,02);

INSERT INTO controlehorasaux VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,null,01,03);
INSERT INTO controlehorasaux VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,null,01,03);
INSERT INTO controlehorasaux VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,null,01,03);
INSERT INTO controlehorasaux VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,null,01,03);