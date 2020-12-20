--------------------------------------------------------
--  DDL for Trigger RECLAMATION_TRIGGER
--------------------------------------------------------

  CREATE OR REPLACE TRIGGER "RIMA"."RECLAMATION_TRIGGER" 
BEFORE INSERT ON RECLAMATION 
FOR EACH ROW
BEGIN 
:new.ID:= ID_Reclamation.nextval; 
END; 

/
ALTER TRIGGER "RIMA"."RECLAMATION_TRIGGER" ENABLE;
