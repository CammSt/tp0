#include "client.h"
#include <readline/readline.h>
#include <readline/history.h>

int main(void) {
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	
	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger, "Hola! Soy un log");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void) {
	t_log* nuevo_logger;
	nuevo_logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);

	// "tp0.log" → nombre del archivo donde se guarda el log.
	// "TP0" → nombre del programa (puede ser cualquier string).
	// true → indica que también se imprime por consola.
	// LOG_LEVEL_INFO → nivel mínimo de log que se va a mostrar (hay DEBUG, INFO, ERROR, etc).

	return nuevo_logger;
}

t_config* iniciar_config(void) { 
	t_config* nuevo_config = config_create("cliente.config");

	if (nuevo_config == NULL) {
		printf("No se pudo abrir el archivo de configuración\n");
		abort();
	}

	char* valor = config_get_string_value(nuevo_config, "CLAVE");
	printf("Valor de CLAVE: %s\n", valor);

	return nuevo_config;
}

void leer_consola(t_log* logger) {
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while (strcmp(leido, "") != 0) {
		log_info(logger, "%s", leido);
		free(leido);
		leido = readline("> ");
	}

	// ¡No te olvides de liberar las lineas antes de regresar!
	free(leido);
}

void paquete(int conexion) {
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config) {
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */

	log_destroy(logger);
	config_destroy(config);
}
