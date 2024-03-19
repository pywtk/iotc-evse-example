/*
 * THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Copyright (C) 2019 Trusted Objects. All rights reserved.
 */

/**
 * @file TOSE_secmsg.h
 * @brief
 */

#ifndef _TOSE_SECMSG_H_
#define _TOSE_SECMSG_H_

#ifndef TOSE_SECMSG_API
#ifdef __linux__
#define TOSE_SECMSG_API
#elif _WIN32
#define TOSE_SECMSG_API __declspec(dllexport)
#else
#define TOSE_SECMSG_API
#endif /* __LINUX__ */
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "TO_defs.h"

/** @addtogroup secmsg_old_api
 * @{ */

/**
 * @brief Transforms a message into a secured message (AES128-CBC cryptogram
 * and HMAC tag).
 * @param[in] ctx Pointer to the SE context
 * @param[in] aes_key_index Index of the key to use for data encryption, starting
 * from 0
 * @param[in] hmac_key_index Index of the key to use for HMAC, starting from 0
 * @param[in] data Message to be secured
 * @param[in] data_length
 * @param[out] initial_vector Block of 16 random bytes generated by the Secure
 * Element and required to decrypt the data
 * @param[out] cryptogram Message cryptogram (same size as data)
 * @param[out] hmac Message HMAC
 *
 * It is equivalent to call TOSE_aes128cbc_encrypt() command, then
 * TOSE_compute_hmac() on the result.
 * The HMAC tag is calculated on encrypted data.
 * Typical use is to have the same value to both AES and HMAC Key indexes.
 * If remote public key is known and trusted by the Secure Element, the Secure
 * Element’s public key could be added to the result of this command and could
 * be used on to have one way only communication network (from Secure Element
 * to remote only).
 *
 * Note: As padding is not handled by the the Secure Element, you must ensure
 * that data length is a multiple of 16 and is not greater than maximum length
 * value (512 bytes).
 * Initial vector is generated by the Secure Element and not included in the
 * data length
 *
 * This API is deprecated, use TOSE_secure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_aes128cbc_hmac_secure_message(TOSE_ctx_t *ctx, const uint8_t aes_key_index,
		const uint8_t hmac_key_index,
		const uint8_t* data, const uint16_t data_length,
		uint8_t initial_vector[TO_INITIALVECTOR_SIZE],
		uint8_t* cryptogram, uint8_t hmac[TO_HMAC_SIZE]
) TO_DEPRECATED;

/**
 * @brief Get back a message from a secured message (AES128-CBC cryptogram and
 * HMAC tag).
 * @param[in] ctx Pointer to the SE context
 * @param[in] aes_key_index Index of the key to use for data decryption, starting
 * from 0
 * @param[in] hmac_key_index Index of the key to use for HMAC verification,
 * starting from 0
 * @param[in] initial_vector Initial vector for decryption
 * @param[in] cryptogram Message cryptogram
 * @param[in] cryptogram_length
 * @param[in] hmac Expected HMAC
 * @param[out] data Decrypted data
 *
 * Data are decrypted only if the HMAC tag is valid.
 *
 * This API is deprecated, use TOSE_unsecure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_aes128cbc_hmac_unsecure_message(TOSE_ctx_t *ctx, const uint8_t aes_key_index,
		const uint8_t hmac_key_index,
		const uint8_t initial_vector[TO_INITIALVECTOR_SIZE],
		const uint8_t* cryptogram, const uint16_t cryptogram_length,
		const uint8_t hmac[TO_HMAC_SIZE],
		uint8_t* data
) TO_DEPRECATED;

/**
 * @brief Transforms a message into a secured message (AES128-CBC cryptogram
 * and CMAC tag).
 * @param[in] ctx Pointer to the SE context
 * @param[in] aes_key_index Index of the key to use for data encryption, starting
 * from 0
 * @param[in] cmac_key_index Index of the key to use for CMAC, starting from 0
 * @param[in] data Message to be secured
 * @param[in] data_length
 * @param[out] initial_vector Block of 16 random bytes generated by the Secure
 * Element and required to decrypt the data
 * @param[out] cryptogram Message cryptogram (same size as data)
 * @param[out] cmac Message CMAC
 *
 * It is equivalent to call TOSE_aes128cbc_encrypt() command, then
 * TOSE_compute_cmac() on the result.
 * The CMAC tag is calculated on encrypted data.
 * Typical use is to have the same value to both AES and CMAC Key indexes.
 * If remote public key is known and trusted by the Secure Element, the Secure
 * Element’s public key could be added to the result of this command and could
 * be used on to have one way only communication network (from Secure Element
 * to remote only).
 *
 * Note: As padding is not handled by the Secure Element, you must ensure that
 * data length is a multiple of 16 and is not greater than maximum length value
 * (512 bytes).
 * Initial vector is generated by the Secure Element and not included in the
 * data length
 *
 * This API is deprecated, use TOSE_secure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_aes128cbc_cmac_secure_message(TOSE_ctx_t *ctx, const uint8_t aes_key_index,
		const uint8_t cmac_key_index,
		const uint8_t* data, const uint16_t data_length,
		uint8_t initial_vector[TO_INITIALVECTOR_SIZE],
		uint8_t* cryptogram, uint8_t cmac[TO_CMAC_SIZE]
) TO_DEPRECATED;

/**
 * @brief Get back a message from a secured message (AES128-CBC cryptogram and
 * CMAC tag).
 * @param[in] ctx Pointer to the SE context
 * @param[in] aes_key_index Index of the key to use for data decryption, starting
 * from 0
 * @param[in] cmac_key_index Index of the key to use for CMAC verification,
 * starting from 0
 * @param[in] initial_vector Initial vector for decryption
 * @param[in] cryptogram Message cryptogram
 * @param[in] cryptogram_length
 * @param[in] cmac Expected CMAC
 * @param[out] data Decrypted data
 *
 * Data are decrypted only if the CMAC tag is valid.
 *
 * This API is deprecated, use TOSE_unsecure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_aes128cbc_cmac_unsecure_message(TOSE_ctx_t *ctx, const uint8_t aes_key_index,
		const uint8_t cmac_key_index,
		const uint8_t initial_vector[TO_INITIALVECTOR_SIZE],
		const uint8_t* cryptogram, const uint16_t cryptogram_length,
		const uint8_t cmac[TO_CMAC_SIZE],
		uint8_t* data
) TO_DEPRECATED;

/** @} */

/** @addtogroup secmsg
 * @{ */

/**
 * @brief Transforms a message into a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] key_index Index of the keys to use for data encryption and MAC,
 * starting from 0
 * @param[in] enc_alg Encryption algorithm to use
 * @param[in] mac_alg MAC algorithm to use
 * @param[in] data Message to be secured
 * @param[in] data_len Message length
 * @param[out] payload Payload
 * @param[out] payload_len Payload length
 *
 * The MAC tag is calculated on clear data, including sequence counter.
 * This function will add padding after MAC if clear data size is not aligned.
 * Padding scheme is PKCS7 with extra padding length byte (TLS like).
 *
 * Initial vector is generated by the Secure Element and not included in the
 * data length
 *
 * Payload length is given by TO_PAYLOAD_SECURED_PAYLOAD_SIZE().
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_secure_payload(TOSE_ctx_t *ctx, const uint8_t key_index,
		const TO_enc_alg_t enc_alg, const TO_mac_alg_t mac_alg,
		const uint8_t* data, const uint16_t data_len,
		uint8_t* payload, uint16_t* payload_len);

/**
 * @brief Get back a message from a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] key_index Index of the keys to use for data encryption and MAC,
 * starting from 0
 * @param[in] enc_alg Encryption algorithm to use
 * @param[in] mac_alg MAC algorithm to use
 * @param[in] payload Payload
 * @param[in] payload_len Payload length
 * @param[out] data Message unsecured
 * @param[out] data_len Message length
 *
 * The MAC tag is verified on clear data, including sequence counter.
 * This function will remove padding.
 * Padding scheme is PKCS7 with extra padding length byte (TLS like).
 *
 * Maximal data length is given by TO_PAYLOAD_CLEAR_DATA_SIZE().
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_unsecure_payload(TOSE_ctx_t *ctx, const uint8_t key_index,
		const TO_enc_alg_t enc_alg, const TO_mac_alg_t mac_alg,
		const uint8_t* payload, const uint16_t payload_len,
		uint8_t* data, uint16_t* data_len);

/** @} */

/** @addtogroup secmsg_capi
 * @{ */

/**
 * @brief Initializes transform of a message into a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] key_index Index of the keys to use for data encryption and MAC,
 * starting from 0
 * @param[in] enc_alg Encryption algorithm to use
 * @param[in] mac_alg MAC algorithm to use
 * @param[in] data_len Full data length
 * @param[in] sequence Sequence counter to avoid replay attacks
 * @param[out] iv Initial vector
 * @param[out] iv_len Initial vector length
 *
 * Initial vector is generated by the Secure Element and not included in the
 * data length
 *
 * Initial vector length is also given by TO_PAYLOAD_IV_SIZE().
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_secure_payload_init(TOSE_ctx_t *ctx, const uint8_t key_index,
		const TO_enc_alg_t enc_alg, const TO_mac_alg_t mac_alg,
		const uint16_t data_len, uint8_t sequence[TO_SEQUENCE_SIZE],
		uint8_t *iv, uint16_t *iv_len);

/**
 * @brief Updates transform of a message into a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] data Message part to be secured
 * @param[in] data_len Message part length (must be multiple of 16)
 * @param[out] cryptogram Message cryptogram (same length)
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_secure_payload_update(TOSE_ctx_t *ctx, const uint8_t* data,
		const uint16_t data_len, uint8_t* cryptogram);

/**
 * @brief Finaliazes transform of a message into a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] data Final message part to be secured
 * @param[in] data_len Final message part length (0 <= data_len < 16)
 * @param[out] cryptogram Final message cryptogram (containing MAC and padding)
 * @param[out] cryptogram_len Final message cryptogram length
 *
 * The MAC tag is calculated on clear data, including sequence counter.
 * This function will add padding after MAC if clear data size is not aligned.
 * Padding scheme is PKCS7 with extra padding length byte (TLS like).
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_secure_payload_final(TOSE_ctx_t *ctx, const uint8_t* data, const uint16_t data_len,
		uint8_t* cryptogram, uint16_t* cryptogram_len);

/**
 * @brief Initializes to get back a message from a secured payload (CBC).
 * @param[in] ctx Pointer to the SE context
 * @param[in] key_index Index of the keys to use for data encryption and MAC,
 * starting from 0
 * @param[in] enc_alg Encryption algorithm to use
 * @param[in] mac_alg MAC algorithm to use
 * @param[in] cryptogram_len Cryptogram length
 * @param[in] sequence Sequence counter to avoid replay attacks
 * @param[in] initial_vector Block of 16 random bytes generated by the Secure
 * Element and required to decrypt the data
 * @param[in] last_block_iv Last AES block initial vector (penultimate block)
 * @param[in] last_block Last AES block
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_unsecure_payload_init_cbc(TOSE_ctx_t *ctx, const uint8_t key_index,
		const TO_enc_alg_t enc_alg, const TO_mac_alg_t mac_alg,
		const uint16_t cryptogram_len, const uint8_t sequence[TO_SEQUENCE_SIZE],
		const uint8_t initial_vector[TO_INITIALVECTOR_SIZE],
		const uint8_t last_block_iv[TO_INITIALVECTOR_SIZE],
		const uint8_t last_block[TO_AES_BLOCK_SIZE]);

/**
 * @brief Initializes to get back a message from a secured payload (AEAD).
 * @param[in] ctx Pointer to the SE context
 * @param[in] key_index Index of the keys to use for data encryption and MAC,
 * starting from 0
 * @param[in] enc_alg Encryption algorithm to use
 * @param[in] mac_alg MAC algorithm to use
 * @param[in] cryptogram_len Cryptogram length
 * @param[in] sequence Sequence counter to avoid replay attacks
 *
 * Do not use this function directly, use TOSE_helper_unsecure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_unsecure_payload_init_aead(TOSE_ctx_t *ctx, const uint8_t key_index,
		const TO_enc_alg_t enc_alg, const TO_mac_alg_t mac_alg,
		const uint16_t cryptogram_len,
		const uint8_t sequence[TO_SEQUENCE_SIZE]);

/**
 * @brief Updates to get back a message from a secured payload.
 * @param[in] ctx Pointer to the SE context
 * @param[in] cryptogram Message cryptogram
 * @param[in] cryptogram_len Message cryptogram length
 * @param[out] data Message unsecured
 * @param[out] data_len Message length
 *
 * Do not use this function directly, use TOSE_helper_unsecure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_unsecure_payload_update(TOSE_ctx_t *ctx, const uint8_t* cryptogram,
		const uint16_t cryptogram_len, uint8_t* data, uint16_t* data_len);

/**
 * @brief Finalizes to get back a message from a secured payload.
 * @param[in] ctx Pointer to the SE context
 *
 * Do not use this function directly, use TOSE_helper_unsecure_payload() instead.
 *
 * @return
 * - TORSP_SUCCESS on success
 * - TORSP_ARG_OUT_OF_RANGE: invalid key index
 * - TORSP_NOT_AVAILABLE: algorithm not available
 * - TO_DEVICE_WRITE_ERROR: error writing data to Secure Element
 * - TO_DEVICE_READ_ERROR: error reading data from Secure Element
 * - TO_INVALID_RESPONSE_LENGTH: unexpected response length from device
 * - TO_MEMORY_ERROR: internal I/O buffer overflow
 * - TO_ERROR: generic error
 */
TOSE_SECMSG_API TO_ret_t TOSE_unsecure_payload_final(TOSE_ctx_t *ctx);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* _TOSE_SECMSG_H_ */

