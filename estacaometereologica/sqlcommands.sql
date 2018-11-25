INSERT INTO `metereologia`.`medicoes`
(`data`,
`hora`,
`umidade`,
`temperatura`)
VALUES
("2018-11-22",
"12:03",
85,
21);
CREATE TABLE `metereologia`.`medicoes` (
  `ID` int not null primary key AUTO_INCREMENT,
  `data` date,
  `hora` time,
  `umidade` int,
  `temperatura` int
)

SELECT AVG(umidade), AVG(temperatura) from metereologia.medicoes where (data = '2018-11-22' AND hora between '11:58:00' and '12:02:00');
SELECT min(umidade), min(temperatura) from metereologia.medicoes where (data = "2018-11-22" AND hora >= "12:00:00");
SELECT max(umidade), max(temperatura) from metereologia.medicoes where (data = "2018-11-22" AND hora >= "12:00:00");
select * from metereologia.medicoes order by ID desc LIMIT 1;
