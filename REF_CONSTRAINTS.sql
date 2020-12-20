--------------------------------------------------------
--  Ref Constraints for Table EMPLOYE_MISSION
--------------------------------------------------------

  ALTER TABLE "RIMA"."EMPLOYE_MISSION" ADD CONSTRAINT "FK10" FOREIGN KEY ("ID_MISSION")
	  REFERENCES "RIMA"."MISSION" ("ID_MISSION") ENABLE;
  ALTER TABLE "RIMA"."EMPLOYE_MISSION" ADD CONSTRAINT "FK11" FOREIGN KEY ("CIN")
	  REFERENCES "RIMA"."EMPLOYE" ("CIN") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table EMPLOYE_RAMASSAGE
--------------------------------------------------------

  ALTER TABLE "RIMA"."EMPLOYE_RAMASSAGE" ADD CONSTRAINT "EMPLOYE_RAMASSAGE_FK1" FOREIGN KEY ("ID_RAMASSAGE")
	  REFERENCES "RIMA"."RAMASSAGE" ("ID_RAMASSAGE") ENABLE;
  ALTER TABLE "RIMA"."EMPLOYE_RAMASSAGE" ADD CONSTRAINT "FK100" FOREIGN KEY ("CIN")
	  REFERENCES "RIMA"."EMPLOYE" ("CIN") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table MISSION_MARCHANT
--------------------------------------------------------

  ALTER TABLE "RIMA"."MISSION_MARCHANT" ADD CONSTRAINT "FK14" FOREIGN KEY ("ID_MISSION")
	  REFERENCES "RIMA"."MISSION" ("ID_MISSION") ENABLE;
  ALTER TABLE "RIMA"."MISSION_MARCHANT" ADD CONSTRAINT "FK140" FOREIGN KEY ("ID_MARCHANT")
	  REFERENCES "RIMA"."MARCHANT" ("ID_MARCHANT") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table RECLAMATION
--------------------------------------------------------

  ALTER TABLE "RIMA"."RECLAMATION" ADD CONSTRAINT "RECLAMATION_FK112" FOREIGN KEY ("ID_COMP")
	  REFERENCES "RIMA"."RESSOURCE" ("ID") ENABLE;
