s = serial('COM9', 'BaudRate', 9600); % Crear un objeto de comunicación serial
fopen(s); % Abrir el puerto serial

fprintf(s, '1'); % Enviar datos al Arduino
pause(1);
%data = fread(s, s.BytesAvailable); % Leer los datos del Arduino

fclose(s); % Cerrar el puerto serial
delete(s); % Borrar el objeto de comunicación serial
