--------------------------------------------------------
--  Fichier cr�� - mardi-mars-01-2022   
--------------------------------------------------------
DROP TABLE "MED"."ADHERENT";
DROP TABLE "MED"."FAMILLES";
DROP TABLE "MED"."PANIER";
DROP TABLE "MED"."PERSONNEL";
DROP TABLE "MED"."PRODUIT";
DROP TABLE "MED"."RECEVOIR";
--------------------------------------------------------
--  DDL for Table ADHERENT
--------------------------------------------------------

  CREATE TABLE "MED"."ADHERENT" 
   (	"ID_ADHERENT" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"MAIL" VARCHAR2(50 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table FAMILLES
--------------------------------------------------------

  CREATE TABLE "MED"."FAMILLES" 
   (	"ID_FAMILLE" NUMBER, 
	"NOM" VARCHAR2(50 BYTE), 
	"PRENOM" VARCHAR2(40 BYTE), 
	"NBR" NUMBER, 
	"NUMERO" NUMBER, 
	"LOCA" VARCHAR2(20 BYTE), 
	"ID_PANIER" NUMBER, 
	"ID_PERSO" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PANIER
--------------------------------------------------------

  CREATE TABLE "MED"."PANIER" 
   (	"ID_PANIER" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PERSONNEL
--------------------------------------------------------

  CREATE TABLE "MED"."PERSONNEL" 
   (	"ID" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ROLE" VARCHAR2(20 BYTE), 
	"DATE_RECRU" DATE, 
	"MDP" NUMBER, 
	"EMAIL" VARCHAR2(50 BYTE), 
	"PHOTO" VARCHAR2(50 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PRODUIT
--------------------------------------------------------

  CREATE TABLE "MED"."PRODUIT" 
   (	"ID_PRODUIT" NUMBER, 
	"TYPE_PRODUIT" VARCHAR2(20 BYTE), 
	"MARQUE" VARCHAR2(20 BYTE), 
	"LLIBELL�" VARCHAR2(20 BYTE), 
	"CODE_BARRE" NUMBER, 
	"QUANTIT�" NUMBER, 
	"PHOTO" VARCHAR2(20 BYTE), 
	"ID_ADHERENT" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table RECEVOIR
--------------------------------------------------------

  CREATE TABLE "MED"."RECEVOIR" 
   (	"ID_FAMILLE" NUMBER, 
	"ID_PANIER" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into MED.ADHERENT
SET DEFINE OFF;
REM INSERTING into MED.FAMILLES
SET DEFINE OFF;
REM INSERTING into MED.PANIER
SET DEFINE OFF;
REM INSERTING into MED.PERSONNEL
SET DEFINE OFF;
REM INSERTING into MED.PRODUIT
SET DEFINE OFF;
REM INSERTING into MED.RECEVOIR
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index ADHERENT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MED"."ADHERENT_PK" ON "MED"."ADHERENT" ("ID_ADHERENT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index FAMILLES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MED"."FAMILLES_PK" ON "MED"."FAMILLES" ("ID_FAMILLE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PANIER_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MED"."PANIER_PK" ON "MED"."PANIER" ("ID_PANIER") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PERSONNEL_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MED"."PERSONNEL_PK" ON "MED"."PERSONNEL" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PRODUIT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "MED"."PRODUIT_PK" ON "MED"."PRODUIT" ("ID_PRODUIT") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table ADHERENT
--------------------------------------------------------

  ALTER TABLE "MED"."ADHERENT" ADD CONSTRAINT "ADHERENT_PK" PRIMARY KEY ("ID_ADHERENT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MED"."ADHERENT" MODIFY ("ID_ADHERENT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table FAMILLES
--------------------------------------------------------

  ALTER TABLE "MED"."FAMILLES" ADD CONSTRAINT "FAMILLES_PK" PRIMARY KEY ("ID_FAMILLE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MED"."FAMILLES" MODIFY ("ID_FAMILLE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PANIER
--------------------------------------------------------

  ALTER TABLE "MED"."PANIER" ADD CONSTRAINT "PANIER_PK" PRIMARY KEY ("ID_PANIER")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MED"."PANIER" MODIFY ("ID_PANIER" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PERSONNEL
--------------------------------------------------------

  ALTER TABLE "MED"."PERSONNEL" ADD CONSTRAINT "PERSONNEL_PK" PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MED"."PERSONNEL" MODIFY ("ID" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "MED"."PRODUIT" MODIFY ("ID_ADHERENT" NOT NULL ENABLE);
  ALTER TABLE "MED"."PRODUIT" ADD CONSTRAINT "PRODUIT_PK" PRIMARY KEY ("ID_PRODUIT")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "MED"."PRODUIT" MODIFY ("ID_PRODUIT" NOT NULL ENABLE);
--------------------------------------------------------
--  Ref Constraints for Table FAMILLES
--------------------------------------------------------

  ALTER TABLE "MED"."FAMILLES" ADD CONSTRAINT "FAMILLES_FK1" FOREIGN KEY ("ID_PANIER")
	  REFERENCES "MED"."PANIER" ("ID_PANIER") ENABLE;
  ALTER TABLE "MED"."FAMILLES" ADD CONSTRAINT "FAMILLES_FK2" FOREIGN KEY ("ID_PERSO")
	  REFERENCES "MED"."PERSONNEL" ("ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table PRODUIT
--------------------------------------------------------

  ALTER TABLE "MED"."PRODUIT" ADD CONSTRAINT "PRODUIT_FK1" FOREIGN KEY ("ID_ADHERENT")
	  REFERENCES "MED"."ADHERENT" ("ID_ADHERENT") ENABLE;