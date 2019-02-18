--
-- PostgreSQL database dump
--

-- Dumped from database version 10.3
-- Dumped by pg_dump version 10.3

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- Data for Name: codigos_error; Type: TABLE DATA; Schema: public; Owner: usuario
--

COPY public.codigos_error (uuid_codigos_error, id_codigos_error, nombre_codigos_error) FROM stdin;
8e06c781-5ac3-47c1-8255-6c64d530b1cf	1	Usuario o password incorrectos
a23202f9-89c9-49ea-b070-b4140665c69e	3	Peticion incorrecta. Si el error persiste contacte con el administrador (XML no valido)
e1319e3e-24e2-451b-aaae-7283e208992d	2	No se ha encontrado una peticion para este caso. Consulte con el administrador
\.


--
-- Data for Name: marcas; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.marcas (uuid_marcas, nombre_marcas) FROM stdin;
14373c86-0ae6-4ed8-900e-dffefdb83344	somgsom
\.


--
-- Data for Name: dispositivos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.dispositivos (uuid_dispositivos, nombre_dispositivos, uuid_marcas) FROM stdin;
920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	yphone 3grx	14373c86-0ae6-4ed8-900e-dffefdb83344
815cecd0-26f3-11e9-b56e-0800200c9a66	Tomson plus	14373c86-0ae6-4ed8-900e-dffefdb83344
93783d70-26f3-11e9-b56e-0800200c9a66	experia galaxy	14373c86-0ae6-4ed8-900e-dffefdb83344
\.


--
-- Data for Name: estados_reparacion; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.estados_reparacion (uuid_estados_reparacion, nombre_estados_reparacion) FROM stdin;
82bb727f-29db-4547-8488-6c30c2dfcc9b	reparando
6db48c79-a201-44d5-b29c-98fda775c1c0	pendiente
\.


--
-- Data for Name: listado_tiendas; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.listado_tiendas (uuid_listado_tiendas, nombre_listado_tiendas, password_listado_tiendas) FROM stdin;
a91d6f79-330e-4fa5-a27c-fae47d994b09	mediamars	caracola11
\.


--
-- Data for Name: tecnicos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.tecnicos (uuid_tecnicos, nombre_tecnicos, password_tecnicos) FROM stdin;
27e9cc28-56fb-4967-b72e-1615dc614559	Martin horacio fernandez de la cruz	chocolate
364aead0-2d6f-11e9-b56e-0800200c9a66	Juan ignacio fernandez de las flores jimenez	lalala
\.


--
-- Data for Name: ordenes; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.ordenes (uuid_ordenes, cliente_ordenes, uuid_estados_reparacion, uuid_tecnicos, uuid_dispositivos, uuid_listado_tiendas, hora_ordenes) FROM stdin;
9ddeaef9-863e-48d5-8141-e2b86f95b90e	pepito de los palotes	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
395cc4e5-202d-47e3-bf20-5e1914060bd1	juanxxxx	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
166241fd-d730-4bdd-b135-f33622e7ae60	pepe	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
e49484f1-5ac7-4780-b9b5-516b26bcab60	pepe tomas alguilar	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	815cecd0-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
69df0f68-c52c-4fec-bfa2-2691583ccd3f	marti	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
f9ed55a5-2843-497d-8e63-84c885e975a6	lepe	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	815cecd0-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
e43b34e0-2a43-43dc-b728-0c60f06c4027	tu	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
90f9596f-ccea-4450-8110-cbc5753ae262	prueba88	82bb727f-29db-4547-8488-6c30c2dfcc9b	27e9cc28-56fb-4967-b72e-1615dc614559	93783d70-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
decb8395-ec97-4308-af71-a09ed182e7b1	juan	82bb727f-29db-4547-8488-6c30c2dfcc9b	364aead0-2d6f-11e9-b56e-0800200c9a66	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
480acbb0-7621-40a2-adbb-ef7c55b74671	aristoteles	82bb727f-29db-4547-8488-6c30c2dfcc9b	364aead0-2d6f-11e9-b56e-0800200c9a66	815cecd0-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
74cdbade-da1d-4ff4-9d74-401e519140eb	sswww	82bb727f-29db-4547-8488-6c30c2dfcc9b	364aead0-2d6f-11e9-b56e-0800200c9a66	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
07859727-d54d-4682-a8b6-a83372a8e3f6	injeccion	82bb727f-29db-4547-8488-6c30c2dfcc9b	364aead0-2d6f-11e9-b56e-0800200c9a66	920dddb7-3cf5-4e9a-8e2d-4426b1e8973a	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
730b4b84-f929-46e2-ba30-641bcc16f7c0	yoyoyoyoy	82bb727f-29db-4547-8488-6c30c2dfcc9b	364aead0-2d6f-11e9-b56e-0800200c9a66	815cecd0-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
bb3c3e34-56c3-428e-a2a2-ffa2cbcfef93	lalala	6db48c79-a201-44d5-b29c-98fda775c1c0	364aead0-2d6f-11e9-b56e-0800200c9a66	815cecd0-26f3-11e9-b56e-0800200c9a66	a91d6f79-330e-4fa5-a27c-fae47d994b09	2019-02-18 13:04:32.113058
\.


--
-- PostgreSQL database dump complete
--

