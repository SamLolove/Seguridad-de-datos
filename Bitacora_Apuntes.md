# Apuntes — Cómputo de Alto Desempeño / Seguridad de Datos (Tuxter)

## Registro de clase
- **Lunes 19/01/2026**
- (Referencia anterior) **Viernes 26/09/2025 — 08:19 a. m.**
- **Profesor:** Dr. Ismael Jiménez
## Temas y herramientas mencionadas
### Sistemas / Distribuciones
- **Parrot Security OS**
- **Kali Linux**
- Enfoque: entornos de práctica para auditoría y análisis de seguridad (uso ético y con autorización).

### Enfoques de evaluación
- **Black Box**: pruebas donde no se conoce internamente el sistema (se evalúa como “externo”).
- **Parciales**
  - **ATtiny85** — 1er parcial
  - **ESP32 (WiFi)** — 2do parcial

## Dispositivos y conceptos asociados (enfoque defensivo)
### ATtiny85
- Microcontrolador con **memoria limitada**.
- Se usa en proyectos pequeños (automatización, emulación de periféricos en laboratorio).
- Consideración de seguridad: **control de puertos USB**, permisos y políticas anti-dispositivos desconocidos.

### ESP32 (WiFi)
- Microcontrolador con conectividad **WiFi/Bluetooth**.
- Útil para proyectos de redes/IoT.
- Consideración de seguridad: segmentación de red, autenticación fuerte, monitoreo de conexiones.

## USB: tipos de riesgos (para imprimir / estudiar)
> **Nota:** Solo para aprendizaje y prevención. Todo debe hacerse **en laboratorio** y con **autorización**.

- **Dispositivos USB “HID” (teclado)**: pueden simular un teclado y ejecutar entradas rápidas.
  - **Defensa:** bloqueo de USB no autorizado, listas blancas, políticas de endpoint.
- **USB con almacenamiento**: riesgo de malware o extracción de datos.
  - **Defensa:** antivirus/EDR, escaneo automático, cifrado, control de copia.
- **USB con funciones de red**: algunos adaptadores crean interfaces de red.
  - **Defensa:** deshabilitar interfaces no aprobadas, monitoreo de red.
- **Diferencias clave**: *cómo se identifican ante el sistema* (teclado/almacenamiento/red) y *qué controles aplican*.

## Redes: escucha de tráfico y datos confidenciales
### Sniffer (escucha de tráfico)
- Un **sniffer** analiza paquetes de red para entender el tráfico.
- Riesgo: si el tráfico no va cifrado, podría exponer **información confidencial**.
- **Defensa:** cifrado, segmentación, redes seguras, monitoreo.

### “Evil Twin” (concepto)
- Ataque donde se imita una red WiFi legítima para engañar usuarios.
- **Defensa:** verificar SSID, usar **WPA2/WPA3**, evitar WiFi abierto, usar VPN institucional si aplica, y capacitación.

## Estados de los datos y cifrado
### Datos en:
- **En tránsito (Transito/Transporte):** cuando viajan por red.
  - Protección: **TLS/SSL**.
- **En reposo (Reposo):** guardados en disco/USB/servidor.
  - Protección: cifrado en disco, control de accesos.
- **En uso (Uso/Proceso):** cuando están en memoria/RAM.
  - Protección: control de procesos, hardening, mínimo privilegio, monitoreo.

### TLS/SSL
- Protocolos para cifrar comunicaciones (principalmente **datos en tránsito**).

## Memoria y forense (idea principal)
- Parte de la actividad: entender que **ciertos contenidos pueden existir temporalmente en memoria (RAM)**.
- Conceptos:
  - **Volcado de memoria (memory dump)**: captura del estado de RAM para análisis forense.
  - Ejemplo conceptual: reproducción de contenido (p. ej. video) puede dejar rastros en memoria durante su ejecución.
- En Windows: se puede hablar de **core dump / memory dump** como evidencia técnica (según configuración y permisos).

## Principios de seguridad (CIA Triad)
- **Confidentiality (Confidencialidad):** que solo acceda quien debe.
- **Integrity (Integridad):** que los datos no se alteren sin autorización.
- **Availability (Disponibilidad):** que la información/servicio esté accesible cuando se necesita.

## No repudio y control de identidades
### Non-Repudiation (No repudio)
- Garantiza que una acción no pueda negarse después.
- Clave: **evitar usuarios genéricos**; usar cuentas individuales y evidencias (logs, firmas, trazabilidad).

### AAA
- **Authentication (Autenticación):** quién eres.
- **Authorization (Autorización):** qué puedes hacer.
- **Accountability (Responsabilidad / Trazabilidad):** registro de quién hizo qué (logs/eventos).

## Recomendaciones de práctica (laboratorio)
- “Cada comando programado, probar por separado”: trabajar por pasos y documentar resultados.
- Uso de **máquina virtual** para pruebas (entorno controlado y reversible).
- Si se requieren adaptadores (ej. “USB 1.0”), anotar compatibilidad y objetivo del laboratorio.


## Palabras clave (para estudiar)
- Parrot Security OS, Kali Linux
- Black box testing
- Sniffer (análisis de tráfico)
- Evil Twin (WiFi)
- TLS/SSL, cifrado en tránsito/en reposo/en uso
- Volcado de memoria / forense
- CIA Triad
- AAA
- No repudio
--
### Registro de clase
- **Miercoles 22/01/2026**

# APUNTES DE CLASE — SEGURIDAD DE DATOS Y REDES (TUXTER)

## CLASE 2 ~~~~~~~~~~~
- **FECHA:** 21/ENERO/2026  
- **PROFESOR:** DR. ISMAEL JIMÉNEZ

---

## 1) TABLA DE HASH (HASH TABLE)
- **DEFINICIÓN:** ESTRUCTURA DE DATOS QUE GUARDA PARES **CLAVE → VALOR**.
- **CÓMO FUNCIONA:** APLICA UNA **FUNCIÓN HASH** A LA CLAVE PARA OBTENER UN ÍNDICE EN LA TABLA.
- **VENTAJA:** BÚSQUEDA RÁPIDA (PROMEDIO **O(1)**).
- **PROBLEMA COMÚN:** **COLISIONES** (DOS CLAVES CAEN EN EL MISMO ÍNDICE).
  - **SOLUCIONES:** ENCADENAMIENTO (LISTAS) O SONDEO (OPEN ADDRESSING).

> **NOTA:** “TABLA DE HASH” (ESTRUCTURA) NO ES LO MISMO QUE “HASH CRIPTOGRÁFICO”.

### HASH CRIPTOGRÁFICO (EN SEGURIDAD)
- **DEFINICIÓN:** “HUELLA” DE LOS DATOS (EJ. SHA-256).
- **USOS:** VERIFICAR **INTEGRIDAD**, DETECTAR CAMBIOS, APOYO EN ALMACENAMIENTO SEGURO DE CONTRASEÑAS (CON SALT).

---

## 2) SECUENCIA (SEQUENCE)
### A) NÚMEROS DE SECUENCIA EN TCP
- TCP NUMERA LOS DATOS PARA ASEGURAR QUE LLEGUEN **EN ORDEN** Y SIN PÉRDIDAS.
- AYUDA A: RETRANSMISIÓN, CONTROL DE FLUJO, EVITAR DUPLICADOS.

### B) SECUENCIA PARA EVITAR “REPLAY”
- EN SEGURIDAD SE USAN **NONCE**, TIMESTAMPS O CONTADORES PARA EVITAR QUE SE REPITA UN MENSAJE VIEJO.
- OBJETIVO: PROTEGER LA **INTEGRIDAD** Y EVITAR REUSO MALICIOSO.

---

## 3) NON-REPUDIATION (NO REPUDIO) — “NO USUARIOS GENÉRICOS”
- **DEFINICIÓN:** PROPIEDAD QUE PERMITE DEMOSTRAR QUE UNA ACCIÓN **SÍ OCURRIÓ** Y **QUIÉN LA REALIZÓ**, EVITANDO QUE LUEGO SE NIEGUE.
- **POR QUÉ NO USUARIOS GENÉRICOS:** SI TODOS USAN “ADMIN” O “USUARIO”, NO HAY TRAZABILIDAD REAL.
- **CÓMO SE APOYA (IDEAS):**
  - CUENTAS INDIVIDUALES
  - REGISTROS (LOGS) Y AUDITORÍA
  - FIRMAS DIGITALES / CERTIFICADOS
  - EVIDENCIA DE “QUIÉN, CUÁNDO, DÓNDE, QUÉ CAMBIÓ”

> **ACLARACIÓN:** “NO REPUDIO” NO ES “QUE NO SE PUEDE MODIFICAR POR UN 3RO”. ESO SE RELACIONA MÁS CON **INTEGRIDAD**.

---

## 4) AAA
### AUTHENTICATION (AUTENTICACIÓN)
- **QUIÉN ERES** (VERIFICACIÓN DE IDENTIDAD).
- EJEMPLOS: CONTRASEÑA, BIOMETRÍA, TOKEN, MFA.

### AUTHORIZATION (AUTORIZACIÓN)
- **QUÉ PUEDES HACER** DESPUÉS DE AUTENTICARTE (PERMISOS).
- EJEMPLOS: ROLES, LECTURA/ESCRITURA, ACCESOS A CARPETAS O SISTEMAS.

### ACCOUNTING / ACCOUNTABILITY (REGISTRO / TRAZABILIDAD)
- **REGISTRO DE EVENTOS:** QUIÉN HIZO QUÉ, CUÁNDO Y DESDE DÓNDE.
- EJEMPLOS: LOGS, BITÁCORAS, AUDITORÍAS EN SISTEMAS Y BASES DE DATOS.

---

## 5) 2FA / MFA / MULTI-STEP
### 2FA (TWO-FACTOR AUTHENTICATION)
- USA **2 FACTORES DIFERENTES** DE ESTAS CATEGORÍAS:
  1) **SABES:** CONTRASEÑA, PIN  
  2) **TIENES:** TOKEN, APP OTP, LLAVE FÍSICA  
  3) **ERES:** BIOMETRÍA (HUELLA, ROSTRO, IRIS)

### MFA (MULTI-FACTOR AUTHENTICATION)
- USA **2 O MÁS FACTORES** (PUEDE SER 2FA O MÁS).

### MULTI-STEP (VARIOS PASOS)
- VARIOS PASOS **NO SIEMPRE** SIGNIFICA MULTIFACTOR.
- EJEMPLO: CONTRASEÑA + PREGUNTA SECRETA (AMBOS SON “SABES”).

### FACTORES BIOMÉTRICOS (EJEMPLOS)
- HUELLAS, ROSTRO, IRIS, VOZ.
- CONCEPTOS:
  - **FAR:** FALSA ACEPTACIÓN
  - **FRR:** FALSO RECHAZO

---

## 6) TRIÁNGULO DE LA USABILIDAD (TRADE-OFF)
- **USABILIDAD:** FÁCIL DE USAR
- **FUNCIONALIDAD:** HACE MÁS COSAS
- **SEGURIDAD:** MÁS CONTROLES Y PROTECCIÓN

> SUBIR MUCHO UNA PUEDE AFECTAR OTRA, DEPENDE DEL CASO DE USO.

---

## 7) CIA TRIAD (TRIADA CIA)
- **CONFIDENTIALITY (CONFIDENCIALIDAD):** SOLO ACCESO A AUTORIZADOS.
- **INTEGRITY (INTEGRIDAD):** DATOS CORRECTOS, SIN ALTERACIÓN NO AUTORIZADA.
- **AVAILABILITY (DISPONIBILIDAD):** SERVICIOS/DATOS DISPONIBLES CUANDO SE NECESITAN.

---

## 8) PARROT SECURITY OS (PARROT SEC)
- DISTRIBUCIÓN LINUX ENFOCADA EN SEGURIDAD, PRIVACIDAD Y PRÁCTICAS DE LABORATORIO.
- USO: APRENDIZAJE, ANÁLISIS Y AUDITORÍA **CON AUTORIZACIÓN**.

---

## 9) EVIL TWIN (CONCEPTO)
- RED WIFI FALSA QUE IMITA UNA RED REAL (MISMO NOMBRE/SSID).
- RIESGO: ROBO DE CREDENCIALES, INTERCEPCIÓN, REDIRECCIONES.
- PREVENCIÓN:
  - EVITAR WIFI ABIERTA
  - NO AUTOCONECTAR
  - PREFERIR WPA2/WPA3
  - VALIDAR ALERTAS/ CERTIFICADOS
  - VPN INSTITUCIONAL SI APLICA

---

## 10) MODELO OSI (7 CAPAS)
1. **FÍSICA**
2. **ENLACE DE DATOS**
3. **RED**
4. **TRANSPORTE**
5. **SESIÓN**
6. **PRESENTACIÓN**
7. **APLICACIÓN**

### CAPAS MENCIONADAS
- **ENLACE DE DATOS = CAPA 2**
- **RED = CAPA 3**
- **TRANSPORTE = CAPA 4**
- **SESIÓN = CAPA 5**

---

## 11) DIRECCIONAMIENTO
### MAC ADDRESS (CAPA 2)
- DIRECCIÓN FÍSICA DE RED (NORMALMENTE **48 BITS**).
- FORMATO: 6 PARES HEXADECIMALES  
  - EJ.: `AA:BB:CC:DD:EE:FF`
- **PRIMEROS 3 BYTES (OUI):** IDENTIFICAN FABRICANTE (VENDOR).
- RIESGO: **MAC SPOOFING** (SUPLANTACIÓN DE MAC).

### IP (CAPA 3)
- DIRECCIÓN LÓGICA.
- IPv4 EN **DOT-DECIMAL NOTATION**: EJ. `192.168.1.10`
- IMPORTANTE (EJEMPLO /24):
  - `192.168.1.0` = RED (NORMALMENTE)
  - `192.168.1.255` = BROADCAST (NORMALMENTE)
  - HOSTS = `192.168.1.1` A `192.168.1.254` (DEPENDE DE MÁSCARA)

---

## 12) ARP Y TABLAS
### ARP (ADDRESS RESOLUTION PROTOCOL)
- TRADUCE **IP → MAC** DENTRO DE UNA RED LOCAL.
- USA UNA **ARP CACHE** (TABLA TEMPORAL).

### MAC ADDRESS TABLE (SWITCH)
- EL SWITCH APRENDE QUÉ **MAC** ESTÁ EN QUÉ **PUERTO**.
- PERMITE “CONMUTAR” (ENVIAR SOLO AL PUERTO CORRECTO).

---

## 13) SWITCH DE CAPA 3
- ADEMÁS DE CONMUTAR (L2), PUEDE **ENRUTAR** (L3).
- ÚTIL PARA VLANs, SEGMENTACIÓN, REDES GRANDES.

---

## 14) PUERTOS (CAPA DE TRANSPORTE)
- RANGO TOTAL: **0 A 65535** (2^16 = 65,536).
- RANGOS TÍPICOS:
  - **0–1023:** WELL-KNOWN
  - **1024–49151:** REGISTERED
  - **49152–65535:** DINÁMICOS/EFÍMEROS
- NOTA: EL **PUERTO 0** ES RESERVADO Y NO SE USA NORMALMENTE COMO PUERTO DESTINO EN CONEXIONES COMUNES.

### PUERTOS COMUNES (REFERENCIA)
- **HTTP:** 80  
- **HTTPS:** 443  
- **DNS:** 53  

### “VERSIONES SEGURAS” (EJEMPLOS)
- **IMAP 143 → IMAPS 993**
- **POP3 110 → POP3S 995**
- **HTTP 80 → HTTPS 443**
- DNS PUEDE CIFRARSE CON:
  - **DoT:** 853
  - **DoH:** 443

---

## 15) TCP VS UDP
### TCP
- ORIENTADO A CONEXIÓN, CONFIABLE (CONFIRMA ENTREGA).
- **3-WAY HANDSHAKE:**
  - SYN → SYN-ACK → ACK

### UDP
- SIN CONEXIÓN, MÁS LIGERO, NO GARANTIZA ENTREGA.
- USO COMÚN: STREAMING, VoIP, DNS (MUCHAS VECES).

---

## 16) WIRESHARK
- HERRAMIENTA PARA **CAPTURAR Y ANALIZAR TRÁFICO DE RED**.
- USO: APRENDIZAJE, TROUBLESHOOTING Y AUDITORÍA **AUTORIZADA**.
- IDEA CLAVE: SIN CIFRADO PUEDE EXPONER DATOS; CON CIFRADO SE PROTEGE **CONFIDENCIALIDAD**.

---
