drop database pi3;

create database pi3;

USE pi3;
CREATE TABLE usuario(
id integer not null primary key auto_increment,
nome  varchar (50) not null,
login varchar (20) not null,
senha varchar (20) not null,
nivel integer not null);

/*
CREATE TABLE empresa(
id integer not null primary key,
cnpj  varchar (20) not null,
nomefantasia varchar (50) not null,
razaosocial varchar (50) not null,
insmunicipal integer not null);
CREATE TABLE departamento(
id integer not null primary key,
nome varchar (50) not null,
cidade varchar (50) not null,
uf varchar (2) not null,
id_tab_empresa integer not null,
constraint fk_departamento_empresa foreign key (id_tab_empresa) references empresa(id));
CREATE TABLE centrocusto(
id integer not null primary key,
nome varchar (30) not null,
id_tab_departamento integer not null,
constraint fk_centrocusto_departamento foreign key (id_tab_departamento) references centrocusto(id));
*/

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
/*id_tab_centrocusto integer not null,*/
/*constraint fk_funcionario_centrocusto foreign key (id_tab_centrocusto) references centrocusto(id));*/

CREATE TABLE controlehoras(
data1 date not null,
tipodia integer not null,
hrsentrada1 time not null,
hrssaida1 time not null,
hrsentrada2 time not null,
hrssaida2 time not null,
hrs100 time null,
hrs50 time null,
adcnoturno time null,
id_tab_periodo integer not null,
id_tab_funcionario integer not null,
constraint fk_controlehoras_periodo foreign key (id_tab_periodo) references periodo(id),
constraint fk_controlehoras_funcionario foreign key (id_tab_funcionario) references funcionario(id),
primary key (data1,id_tab_periodo, id_tab_funcionario, data1));

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

/*
select * from usuario;
select * from empresa;
select * from departamento;
select * from centrocusto;
select * from periodo;
select * from funcionario;
select * from controlehoras;
select * from cargo;
select * from ocupa;
select * from controlehoras;
*/

INSERT INTO usuario VALUES (null,'LOURIVAL VICENTE DA SILVA JUNIOR','LOURIVAL','123456789',1);
INSERT INTO usuario VALUES (null,'ROMILDO ALVES DE SOUZA JUNIOR','ROMILDO','123456789',2);
INSERT INTO usuario VALUES (null,'MAIDSON MATEUS SILVA SOUZA','MAIDSON','123456789',3);

/*
INSERT INTO empresa VALUES (01,'111111111','VIA RADIO', 'STATUS EQUIPAMENTO DE TELECOM LTDA',11112222);
INSERT INTO empresa VALUES (02,'222222222','BRASILAGRO', 'COMPANHIA DE SERVICO E RURAL LTDA',22223333);
INSERT INTO empresa VALUES (03,'333333333','MUNDO INFORMATICA', 'PRESTAÇAO DE SERVIÇO E VENDA TECNOLOGIA',33334444);
INSERT INTO departamento VALUES (01,'FINANCEIRO','JATAI', 'GO',01);
INSERT INTO departamento VALUES (02,'VENDA','JATAI', 'GO',01);
INSERT INTO departamento VALUES (03,'ALMOXARIFADO','RIO VERDE', 'GO',01);
INSERT INTO departamento VALUES (04,'COMPRAS','JATAI', 'GO',02);
INSERT INTO departamento VALUES (05,'AGRICOLA','MINEIRO', 'GO',02);
INSERT INTO departamento VALUES (06,'FABRICA','URUACU', 'MT',02);
INSERT INTO departamento VALUES (07,'GESTAO','JATAI', 'GO',03);
INSERT INTO departamento VALUES (08,'RH','GOIANIA', 'GO',03);
INSERT INTO departamento VALUES (09,'VENDA','APARECIDA', 'GO',03);
INSERT INTO centrocusto VALUES (01,'111-EPI',01);
INSERT INTO centrocusto VALUES (02,'222-LAVANDARIA',02);
INSERT INTO centrocusto VALUES (03,'333-MARCAÇAO',03);
INSERT INTO centrocusto VALUES (05,'444-MAQUINAS',03);
INSERT INTO centrocusto VALUES (06,'555-ADUBO',02);
INSERT INTO centrocusto VALUES (07,'666-DOENÇA',01);
INSERT INTO centrocusto VALUES (08,'777-FINANCEIRO',01);
*/

INSERT INTO periodo VALUES (null,'F',20190506,20190531);
INSERT INTO periodo VALUES (null,'N',20190606,20190606);
INSERT INTO periodo VALUES (null,'N',20190706,20190731);

INSERT INTO funcionario VALUES (NULL,'LOURIVAL JUNIOR',36368239,'RUA ANGICO 88','FLORESTA','JATAI','GO');
INSERT INTO funcionario VALUES (null,'ROMILDO JUNIOR',36361400,'RUA MINAS 101','FATIMA','JATAI','GO');
INSERT INTO funcionario VALUES (null,'MAISDON MATEUS',36361300,'RUA ROTA 123','ANTENA','JATAI','GO');

INSERT INTO cargo VALUES (null,'ELETRICISTA',2300.00);
INSERT INTO cargo VALUES (null,'ANALISTA RH',2000.00);
INSERT INTO cargo VALUES (null,'SERVICOGERAIS',2100.00);

INSERT INTO ocupa VALUES (20190101,20190130,01,01,500.00);
INSERT INTO ocupa VALUES (20190101,20190130,02,02,500.00);
INSERT INTO ocupa VALUES (20190101,20190130,03,03,600.00);

INSERT INTO controlehoras VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,01,01);
INSERT INTO controlehoras VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,01,01);
INSERT INTO controlehoras VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,01,01);
INSERT INTO controlehoras VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,01,01);

INSERT INTO controlehoras VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,01,02);
INSERT INTO controlehoras VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,01,02);
INSERT INTO controlehoras VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,01,02);
INSERT INTO controlehoras VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,01,02);

INSERT INTO controlehoras VALUES (20190101,'1',080000,110000,123000,173000,null,null,null,01,03);
INSERT INTO controlehoras VALUES (20190102,'1',080000,110000,123000,173000,null,null,null,01,03);
INSERT INTO controlehoras VALUES (20190103,'1',080000,110000,123000,173000,null,null,null,01,03);
INSERT INTO controlehoras VALUES (20190104,'1',080000,110000,123000,173000,null,null,null,01,03);