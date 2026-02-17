# Bitácora de clase  
## Fundamentos de Seguridad de la Información (Resumen)

**Materia:** Seguridad de Datos  
**Estudiante:** _Samantha Camila Durán González_  
**Fecha:** 16/02/2026  

---

## 1) Triada CIA (Confidentiality, Integrity, Availability)

La **Triada CIA** se usa como base para entender qué es “proteger información”. Se enfoca en 3 objetivos:

###  Confidencialidad (Confidentiality)
Busca que los datos **solo los vean personas autorizadas**.

**Ejemplos:**
- Cifrado de archivos y comunicaciones (TLS/SSL)
- Control de accesos por roles
- MFA / contraseñas seguras

###  Integridad (Integrity)
Asegura que la información **no sea modificada** sin permiso y se mantenga correcta.

**Ejemplos:**
- Hashes (SHA-256) para validar archivos
- Firmas digitales
- Control de cambios / bitácoras

###  Disponibilidad (Availability)
Garantiza que los sistemas y datos estén disponibles **cuando se necesiten**.

**Ejemplos:**
- Backups y recuperación (DRP)
- Redundancia (servidores/servicios)
- Protección ante caídas o saturación

---

## 2) AAA (Authentication, Authorization, Accountability)

El modelo **AAA** ayuda a controlar accesos y dejar evidencia de actividades:

- **Authentication (Autenticación):** confirma **quién eres**  
  - Ej.: contraseña, biometría, token

- **Authorization (Autorización):** define **qué puedes hacer**  
  - Ej.: permisos de lectura/escritura, roles

- **Accountability (Registro / trazabilidad):** deja evidencia de **quién hizo qué**  
  - Ej.: logs de inicio de sesión, auditorías de cambios

---

## 3) No Repudio (Non-repudiation)
El **no repudio** significa que se puede demostrar que una acción ocurrió y **quién la realizó**.

### Idea clave
- Evitar **usuarios genéricos** (ej. “ADMIN”, “INVITADO”) porque se pierde la trazabilidad.

**Ejemplos de apoyo:**
- Cuentas individuales
- Logs/auditoría
- Firmas digitales

---

## 4) 2FA vs MFA (y multi-step)

### 2FA (Two-Factor Authentication)
Usa **2 factores distintos**:
1) Algo que **sabes** (contraseña/PIN)  
2) Algo que **tienes** (token/celular)  
3) Algo que **eres** (biometría)

### MFA (Multi-Factor Authentication)
Usa **2 o más** factores (puede ser 2FA o más).

### Multi-step
Varios pasos no siempre es MFA si son del mismo tipo (ej. contraseña + pregunta secreta = “sabes”).

---

## 5)  Triángulo de usabilidad
Siempre hay un equilibrio entre:
- **Seguridad**
- **Usabilidad**
- **Funcionalidad**

 Mientras más seguridad se agrega, a veces se complica el uso; por eso se ajusta según el caso.

---

## 6) Modelo TCP/IP (direcciones por capa)
Cada capa “identifica” cosas distintas:

- **Enlace:** MAC Address  
- **Internet:** IP Address  
- **Transporte:** Puertos (TCP/UDP)  
- **Aplicación:** identificadores como **URL** o **correo** (ej. `usuario@gmail.com`)

---

## 7)  Puertos (dato importante)
Los puertos van de **0 a 65,535** porque son **16 bits**:

- **2^16 = 65,536** valores posibles

**Servicios comunes:**
- HTTP → 80/TCP  
- HTTPS → 443/TCP  
- DNS → 53/UDP (y también TCP en algunos casos)

---

## 8) Amenaza, Vulnerabilidad y Exploit
- **Amenaza (Threat):** algo que puede causar daño (actor, evento, situación).
- **Vulnerabilidad:** debilidad en sistema/configuración/proceso.
- **Exploit:** forma de aprovechar una vulnerabilidad para lograr un impacto.

Se conectan así:  
**Amenaza + Vulnerabilidad → (Exploit) → Impacto**

---

## 9) STRIDE (modelo de amenazas)
- **S**poofing (suplantación)  
- **T**ampering (alteración)  
- **R**epudiation (repudio)  
- **I**nformation Disclosure (filtración)  
- **D**enial of Service (interrupción)  
- **E**levation of Privilege (más permisos de los debidos)

---

## 10) MITRE ATT&CK (idea general)
Base de conocimiento que organiza **técnicas y tácticas** usadas en ataques reales.  
Sirve para entender patrones y mejorar defensa, detección y respuesta.

---

## 11) ¿Qué es un hacker?
Persona capaz de hacer que un sistema funcione o se comporte de una forma **para la que no fue diseñado**.  
El enfoque puede ser ético o malicioso, depende de la intención.

### Tipos (básico)
- **White Hat:** ético (con permiso)  
- **Black Hat:** ciberdelincuente  
- **Script Kiddies:** usan herramientas sin entender a fondo  

---

## 12)  Blue Team vs  Red Team
- **Red Team:** simula ataques para probar defensas.  
- **Blue Team:** defiende, monitorea, detecta y responde.

---

#  Conclusión
Estos conceptos (CIA, AAA, no repudio, 2FA/MFA, STRIDE y MITRE) ayudan a entender cómo se protege la información en la práctica. La idea principal es controlar accesos, registrar acciones y reducir riesgos sin perder el equilibrio entre seguridad, usabilidad y funcionalidad.
