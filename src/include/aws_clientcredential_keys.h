#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWTCCAkGgAwIBAgIUTVknLJV4rrWmxZ6KRsKqCLWs0R4wDQYJKoZIhvcNAQEL\n"\
"BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\n"\
"SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTE4MTIyODAyNTI0\n"\
"MVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\n"\
"ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAK6IcdBrUOy/1K2AfACg\n"\
"IbWNLNs9XmfqzNHtUvkjl/zY9JKN5DDshyadJWjr4WbGBhM3EEJz3P0dc+m6G0Ca\n"\
"N+2Dn2Ms+PuBuDZCzqeGf/IvVd8CCFdA4FwGmnt2Y0lPcRS6yBafVUNHR4nA3fHW\n"\
"onQJ98gQ3L4fMpwBy2K6NCJ7rX8YwopTcXEZob68Ncyi2rJYFwXQGCqqc9WPk08l\n"\
"nlbIdtscXR7p+tmt5zXi4U31E+L3/wqIekinxK1WHNjwgISJ8kSiOGJUrmhkbgLz\n"\
"Jbr1UT8tU/IhUYRnz13WIHGjPThD5o3UeDzZIx7N0ST9LOFKbYn6C1LKWBXX6CMX\n"\
"EiMCAwEAAaNgMF4wHwYDVR0jBBgwFoAUVbc16SfF4HcD7gzeu52KTCPF3mcwHQYD\n"\
"VR0OBBYEFMJdaGDKYtbY7ao/WcQn9fA3PNtXMAwGA1UdEwEB/wQCMAAwDgYDVR0P\n"\
"AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAO0mAPPflqYSRL2MHOLOHjpB66\n"\
"MWQZGvEc/DGod60Dod62o2XKXrc466qtQLfxIRQqysWSy5t4dg+rzrQ1bDuqUDv3\n"\
"78Vns4u5u7vFs4dVaGfv5TgP32Q5AG+5gduWBgWJ+vjisuWHLiory9uhRA4qKm+U\n"\
"BczuM3rCKYE/OTT1ti5NqmdAfjNx0J/5eMT9FT7tQF0d+B1cSBFUYiSjtpJyM1mm\n"\
"OEwVTeB31ki//Z+064LnD1atqOeFXs/D5/QloKTXmzNrkuztOanzeiWA6fn81SXZ\n"\
"WkI2L5K+MCPZRgrBpeXWG2mlY1DA0INPk12VxFOE+ZFKJXEdVrucuLLA+v8V\n"\
"-----END CERTIFICATE-----"

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEogIBAAKCAQEArohx0GtQ7L/UrYB8AKAhtY0s2z1eZ+rM0e1S+SOX/Nj0ko3k\n"\
"MOyHJp0laOvhZsYGEzcQQnPc/R1z6bobQJo37YOfYyz4+4G4NkLOp4Z/8i9V3wII\n"\
"V0DgXAaae3ZjSU9xFLrIFp9VQ0dHicDd8daidAn3yBDcvh8ynAHLYro0InutfxjC\n"\
"ilNxcRmhvrw1zKLaslgXBdAYKqpz1Y+TTyWeVsh22xxdHun62a3nNeLhTfUT4vf/\n"\
"Coh6SKfErVYc2PCAhInyRKI4YlSuaGRuAvMluvVRPy1T8iFRhGfPXdYgcaM9OEPm\n"\
"jdR4PNkjHs3RJP0s4UptifoLUspYFdfoIxcSIwIDAQABAoIBAAgOUjqNiYmz/QwZ\n"\
"HyAkRAoOPyDLf10KkHOsIaVQSEaqePd+xyae9EoK/NwP7zKAN22RoBWBJZUlU+FY\n"\
"7sMXmzdCWQwJ2mA5h5gxkzpWUfeKycrmXB4y52g4Ac9rEoAiw5RyXqP0rMnTM3Ef\n"\
"Tt9Hye3TO/WnGZlI9VwQFSQ0dg2VVkiWLzo8ObWdEFSrJ1g4183vWyIJDY3GZw/L\n"\
"ui9l6pSpUgkrTAtEPkthfC/oYbnuTQlWuMy0ZlK1SJH3YdBpcjmsvPTj3B9U85n+\n"\
"dszYXQ8n1LdvUpVdTr5D8MOoKAsu1vkTtzXUM45kbl9cGTxkyru0hLDCmYDdUY1J\n"\
"W6YLAYECgYEA4l9Fsf1gMtvL057w+gzGDVeXLqgn4dhkTRaX1iUZqx4d0Tu804cl\n"\
"+vvS5WqiVO+j82AikrrCCbBVj+ETV8zwmsf1WVWtrzTsubJ3ph0cTVlWf3kDDMHe\n"\
"eMYdeGOUyB8DMAFWjjEPGmfu4/tSmsKPm0l72cWIIieCGFcveTbhV+MCgYEAxWBF\n"\
"f2C8aP7atzZu5yyX/03KuAKU3fv1Ab8no9mOiHTYdNXYc/cIVN1zdXKDhSYJcyN6\n"\
"b6kgJKyqR9FtWzHOa7FT+QSNCN1tH7TRt59/2wulxQ6wKH64eHkBufEfQ+YOpbiw\n"\
"OChZ8N12qiBPaMf6t7fcFZA0ctHYa4fpQ48l8MECgYBvu87O192PvOWSgrU29u8a\n"\
"zs0UfnORChoX4rr3PEC7MZZOHEpLrj2U8I9cJZISkmY+TolCG2SDG8JfzhyaDdIE\n"\
"1AXKHnwoKttdnTVpjJzXoO0M5lIXDeodesw5DA336TbNjxuF+7kUs5A6f2Z6dOYl\n"\
"I9Q53UIgeZfBI+eO0QPROQKBgHUiDfxq/0VcQZZLIoPkzguAMhcDyS738M3pkG/H\n"\
"k7Pdi/vCUON5LiOXDIcdv3mMOj1vR6DugJnjMmbOnZRqOXNl2EzG65/gMHuJho/v\n"\
"gyQOhIEul1Jg6b7tKR4dP42/AOBOe53ILKAp/ds2s4mebGcNIPpXCxk8+a/PB5rF\n"\
"YCHBAoGAbJOycpUO51XilULJQi92HlsniSGguc/Ox/oLLPh/8gGrP054U2Z0KHDk\n"\
"+0FkHO3NkeBdULg5DP5MtEqc/PXrDEcqc0Jhxx2tgf7sl9CMu2protftdaL2vvXU\n"\
"O8cf8j+3ekh0qqtYvq/ENmMFTGj1OPx/0K4LlxNWY9W7WyTzdtc=\n"\
"-----END RSA PRIVATE KEY-----"

/*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  NULL

/* The constants above are set to const char * pointers defined in aws_dev_mode_key_provisioning.c,
 * and externed here for use in C files.  NOTE!  THIS IS DONE FOR CONVENIENCE
 * DURING AN EVALUATION PHASE AND IS NOT GOOD PRACTICE FOR PRODUCTION SYSTEMS
 * WHICH MUST STORE KEYS SECURELY. */
extern const char clientcredentialCLIENT_CERTIFICATE_PEM[];
extern const char* clientcredentialJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM;
extern const char clientcredentialCLIENT_PRIVATE_KEY_PEM[];
extern const uint32_t clientcredentialCLIENT_CERTIFICATE_LENGTH;
extern const uint32_t clientcredentialCLIENT_PRIVATE_KEY_LENGTH;

#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
