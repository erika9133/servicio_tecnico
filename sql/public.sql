/*
 Navicat Premium Data Transfer

 Source Server         : 3r1k4
 Source Server Type    : PostgreSQL
 Source Server Version : 90610
 Source Host           : www.3r1k4.com:5432
 Source Catalog        : servicio_tecnico
 Source Schema         : public

 Target Server Type    : PostgreSQL
 Target Server Version : 90610
 File Encoding         : 65001

 Date: 16/01/2019 23:25:03
*/


-- ----------------------------
-- Table structure for dispositivos
-- ----------------------------
DROP TABLE IF EXISTS "public"."dispositivos";
CREATE TABLE "public"."dispositivos" (
  "uuid_dispositivos" uuid NOT NULL DEFAULT NULL,
  "nombre_dispositivos" varchar COLLATE "pg_catalog"."default" DEFAULT NULL,
  "uuid_marcas" uuid DEFAULT NULL
)
;

-- ----------------------------
-- Table structure for estados_reparacion
-- ----------------------------
DROP TABLE IF EXISTS "public"."estados_reparacion";
CREATE TABLE "public"."estados_reparacion" (
  "uuid_estados_reparacion" uuid NOT NULL DEFAULT NULL,
  "nombre_estados_reparacion" varchar COLLATE "pg_catalog"."default" DEFAULT NULL
)
;

-- ----------------------------
-- Table structure for listado_tiendas
-- ----------------------------
DROP TABLE IF EXISTS "public"."listado_tiendas";
CREATE TABLE "public"."listado_tiendas" (
  "uuid_listado_tiendas" uuid NOT NULL DEFAULT NULL,
  "nombre_listado_tiendas" varchar COLLATE "pg_catalog"."default" DEFAULT NULL
)
;

-- ----------------------------
-- Table structure for marcas
-- ----------------------------
DROP TABLE IF EXISTS "public"."marcas";
CREATE TABLE "public"."marcas" (
  "uuid_marcas" uuid NOT NULL DEFAULT NULL,
  "nombre_marcas" varchar COLLATE "pg_catalog"."default" DEFAULT NULL
)
;

-- ----------------------------
-- Records of marcas
-- ----------------------------
INSERT INTO "public"."marcas" VALUES ('14373c86-0ae6-4ed8-900e-dffefdb83344', 'somgsom');

-- ----------------------------
-- Table structure for ordenes
-- ----------------------------
DROP TABLE IF EXISTS "public"."ordenes";
CREATE TABLE "public"."ordenes" (
  "uuid_ordenes" uuid NOT NULL DEFAULT NULL,
  "cliente_ordenes" varchar COLLATE "pg_catalog"."default" DEFAULT NULL,
  "uuid_estados_reparacion" uuid DEFAULT NULL,
  "uuid_tecnicos" uuid DEFAULT NULL,
  "uuid_dispositivos" uuid DEFAULT NULL,
  "uuid_listado_tiendas" uuid DEFAULT NULL
)
;

-- ----------------------------
-- Records of ordenes
-- ----------------------------
INSERT INTO "public"."ordenes" VALUES ('9ddeaef9-863e-48d5-8141-e2b86f95b90e', 'pepito de los palotes', NULL, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for tecnicos
-- ----------------------------
DROP TABLE IF EXISTS "public"."tecnicos";
CREATE TABLE "public"."tecnicos" (
  "uuid_tecnicos" uuid NOT NULL DEFAULT NULL,
  "nombre_tecnicos" varchar COLLATE "pg_catalog"."default" DEFAULT NULL
)
;

-- ----------------------------
-- Function structure for uuid_generate_v1
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_generate_v1"();
CREATE OR REPLACE FUNCTION "public"."uuid_generate_v1"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_generate_v1'
  LANGUAGE c VOLATILE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_generate_v1mc
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_generate_v1mc"();
CREATE OR REPLACE FUNCTION "public"."uuid_generate_v1mc"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_generate_v1mc'
  LANGUAGE c VOLATILE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_generate_v3
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_generate_v3"("namespace" uuid, "name" text);
CREATE OR REPLACE FUNCTION "public"."uuid_generate_v3"("namespace" uuid, "name" text)
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_generate_v3'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_generate_v4
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_generate_v4"();
CREATE OR REPLACE FUNCTION "public"."uuid_generate_v4"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_generate_v4'
  LANGUAGE c VOLATILE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_generate_v5
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_generate_v5"("namespace" uuid, "name" text);
CREATE OR REPLACE FUNCTION "public"."uuid_generate_v5"("namespace" uuid, "name" text)
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_generate_v5'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_nil
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_nil"();
CREATE OR REPLACE FUNCTION "public"."uuid_nil"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_nil'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_ns_dns
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_ns_dns"();
CREATE OR REPLACE FUNCTION "public"."uuid_ns_dns"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_ns_dns'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_ns_oid
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_ns_oid"();
CREATE OR REPLACE FUNCTION "public"."uuid_ns_oid"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_ns_oid'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_ns_url
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_ns_url"();
CREATE OR REPLACE FUNCTION "public"."uuid_ns_url"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_ns_url'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Function structure for uuid_ns_x500
-- ----------------------------
DROP FUNCTION IF EXISTS "public"."uuid_ns_x500"();
CREATE OR REPLACE FUNCTION "public"."uuid_ns_x500"()
  RETURNS "pg_catalog"."uuid" AS '$libdir/uuid-ossp', 'uuid_ns_x500'
  LANGUAGE c IMMUTABLE STRICT
  COST 1;

-- ----------------------------
-- Primary Key structure for table dispositivos
-- ----------------------------
ALTER TABLE "public"."dispositivos" ADD CONSTRAINT "dispositivos_pkey" PRIMARY KEY ("uuid_dispositivos");

-- ----------------------------
-- Primary Key structure for table estados_reparacion
-- ----------------------------
ALTER TABLE "public"."estados_reparacion" ADD CONSTRAINT "estados_reparacion_pkey" PRIMARY KEY ("uuid_estados_reparacion");

-- ----------------------------
-- Primary Key structure for table listado_tiendas
-- ----------------------------
ALTER TABLE "public"."listado_tiendas" ADD CONSTRAINT "listado_tiendas_pkey" PRIMARY KEY ("uuid_listado_tiendas");

-- ----------------------------
-- Primary Key structure for table marcas
-- ----------------------------
ALTER TABLE "public"."marcas" ADD CONSTRAINT "marcas_pkey" PRIMARY KEY ("uuid_marcas");

-- ----------------------------
-- Primary Key structure for table ordenes
-- ----------------------------
ALTER TABLE "public"."ordenes" ADD CONSTRAINT "ordenes_pkey" PRIMARY KEY ("uuid_ordenes");

-- ----------------------------
-- Primary Key structure for table tecnicos
-- ----------------------------
ALTER TABLE "public"."tecnicos" ADD CONSTRAINT "tecnicos_pkey" PRIMARY KEY ("uuid_tecnicos");

-- ----------------------------
-- Foreign Keys structure for table dispositivos
-- ----------------------------
ALTER TABLE "public"."dispositivos" ADD CONSTRAINT "dispositivos_uuid_marcas_fkey" FOREIGN KEY ("uuid_marcas") REFERENCES "marcas" ("uuid_marcas") ON DELETE NO ACTION ON UPDATE NO ACTION;

-- ----------------------------
-- Foreign Keys structure for table ordenes
-- ----------------------------
ALTER TABLE "public"."ordenes" ADD CONSTRAINT "fk_uuid_dispositivos" FOREIGN KEY ("uuid_dispositivos") REFERENCES "dispositivos" ("uuid_dispositivos") ON DELETE NO ACTION ON UPDATE NO ACTION;
ALTER TABLE "public"."ordenes" ADD CONSTRAINT "fk_uuid_estados_reparacion" FOREIGN KEY ("uuid_estados_reparacion") REFERENCES "estados_reparacion" ("uuid_estados_reparacion") ON DELETE NO ACTION ON UPDATE NO ACTION;
ALTER TABLE "public"."ordenes" ADD CONSTRAINT "fk_uuid_listado_tiendas" FOREIGN KEY ("uuid_listado_tiendas") REFERENCES "listado_tiendas" ("uuid_listado_tiendas") ON DELETE NO ACTION ON UPDATE NO ACTION;
ALTER TABLE "public"."ordenes" ADD CONSTRAINT "fk_uuid_tenicos" FOREIGN KEY ("uuid_tecnicos") REFERENCES "tecnicos" ("uuid_tecnicos") ON DELETE CASCADE ON UPDATE CASCADE;
