#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct Packet {
	uint8_t start1;
	uint8_t start2;
	uint8_t length;
	uint8_t command;
	uint8_t data[16];
	uint8_t checksum;
	
};
uint8_t calculate_checksum(uint8_t *data, uint8_t length) {
	uint8_t checksum = 0;
	for (int i = 0;i < length; i++) {
		checksum ^= data[i];
	}
	return checksum;
}

void parse_packet(uint8_t* raw_data, struct Packet* pkt) {
	pkt->start1 = raw_data[0];
	pkt->start2 = raw_data[1];
	pkt->length = raw_data[2];
	pkt->command = raw_data[3];
	for (int i = 0; i < pkt->length;i++) {
		pkt->data[i] = raw_data[4 + i];
	}
	pkt->checksum = raw_data[4 + pkt->length];
}

int main(void) {
	uint8_t raw_data[] = {0xAA,0x55,0x03,0x01,0x12,0x34,0x56,0x70};
	struct Packet pkt;
	parse_packet(raw_data,&pkt);
	uint8_t calculated_checksum = calculate_checksum(pkt.data, pkt.length);
	if (calculated_checksum == pkt.checksum) {
		printf("Goi tin hop le\n");
	}
	else {
		printf("Goi tin khong hop le!");
	}

}