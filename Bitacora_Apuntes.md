# Apuntes — Cómputo de Alto Desempeño / Seguridad de Datos (Tuxter)

## Registro de clase

- **Lunes 19/01/2026**
- (Referencia anterior) **Viernes 26/09/2025 — 08:19 a. m.**
- **Profesor:** Dr. Ismael Jiménez

---

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

---

## Dispositivos y conceptos asociados (enfoque defensivo)
### ATtiny85
- Microcontrolador con **memoria limitada**.
- Se usa en proyectos pequeños (automatización, emulación de periféricos en laboratorio).
- Consideración de seguridad: **control de puertos USB**, permisos y políticas anti-dispositivos desconocidos.

### ESP32 (WiFi)
- Microcontrolador con conectividad **WiFi/Bluetooth**.
- Útil para proyectos de redes/IoT.
- Consideración de seguridad: segmentación de red, autenticación fuerte, monitoreo de conexiones.

---

## USB: tipos de riesgos (para imprimir / estudiar)
> **Nota:** Solo para aprendizaje y prevención. Todo debe hacerse **en laboratorio** y con **autorización**.

- **Dispositivos USB “HID” (teclado)**: pueden simular un teclado y ejecutar entradas rápidas.
  - **Defensa:** bloqueo de USB no autorizado, listas blancas, políticas de endpoint.
- **USB con almacenamiento**: riesgo de malware o extracción de datos.
  - **Defensa:** antivirus/EDR, escaneo automático, cifrado, control de copia.
- **USB con funciones de red**: algunos adaptadores crean interfaces de red.
  - **Defensa:** deshabilitar interfaces no aprobadas, monitoreo de red.
- **Diferencias clave**: *cómo se identifican ante el sistema* (teclado/almacenamiento/red) y *qué controles aplican*.

---

## Redes: escucha de tráfico y datos confidenciales
### Sniffer (escucha de tráfico)
- Un **sniffer** analiza paquetes de red para entender el tráfico.
- Riesgo: si el tráfico no va cifrado, podría exponer **información confidencial**.
- **Defensa:** cifrado, segmentación, redes seguras, monitoreo.

### “Evil Twin” (concepto)
- Ataque donde se imita una red WiFi legítima para engañar usuarios.
- **Defensa:** verificar SSID, usar **WPA2/WPA3**, evitar WiFi abierto, usar VPN institucional si aplica, y capacitación.

---

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

---

## Memoria y forense (idea principal)
- Parte de la actividad: entender que **ciertos contenidos pueden existir temporalmente en memoria (RAM)**.
- Conceptos:
  - **Volcado de memoria (memory dump)**: captura del estado de RAM para análisis forense.
  - Ejemplo conceptual: reproducción de contenido (p. ej. video) puede dejar rastros en memoria durante su ejecución.
- En Windows: se puede hablar de **core dump / memory dump** como evidencia técnica (según configuración y permisos).

---

## Principios de seguridad (CIA Triad)
- **Confidentiality (Confidencialidad):** que solo acceda quien debe.
- **Integrity (Integridad):** que los datos no se alteren sin autorización.
- **Availability (Disponibilidad):** que la información/servicio esté accesible cuando se necesita.

---

## No repudio y control de identidades
### Non-Repudiation (No repudio)
- Garantiza que una acción no pueda negarse después.
- Clave: **evitar usuarios genéricos**; usar cuentas individuales y evidencias (logs, firmas, trazabilidad).

### AAA
- **Authentication (Autenticación):** quién eres.
- **Authorization (Autorización):** qué puedes hacer.
- **Accountability (Responsabilidad / Trazabilidad):** registro de quién hizo qué (logs/eventos).

---

## Recomendaciones de práctica (laboratorio)
- “Cada comando programado, probar por separado”: trabajar por pasos y documentar resultados.
- Uso de **máquina virtual** para pruebas (entorno controlado y reversible).
- Si se requieren adaptadores (ej. “USB 1.0”), anotar compatibilidad y objetivo del laboratorio.

---

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
