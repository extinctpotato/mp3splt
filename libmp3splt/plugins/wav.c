#include <string.h>

#include "splt.h"
#include "wav.h"

void splt_pl_init(splt_state *state, int *error) {
	FILE *file_input = NULL;
	char *filename = splt_t_get_filename_to_split(state);
}

void splt_pl_end(splt_state *state, splt_code *error) {
}

void splt_pl_set_plugin_info(splt_plugin_info *info, splt_code *error) {
	info->version = 1.0;

	info->name = malloc(20);
	if (info->name == NULL) {
		*error = SPLT_ERROR_CANNOT_ALLOCATE_MEMORY;
		return;
	}
	snprintf(info->name, 19, "wav");

	info->extension = malloc(strlen(SPLT_WAV_EXT)+2);
	if (info->extension == NULL) {
		*error = SPLT_ERROR_CANNOT_ALLOCATE_MEMORY;
		return;
	}
	snprintf(info->extension, strlen(SPLT_WAV_EXT)+1, SPLT_WAV_EXT);

	info->upper_extension = splt_su_convert(info->extension, SPLT_TO_UPPERCASE, error);
}

int splt_pl_check_plugin_is_for_file(splt_state *state, int *error) {
	return SPLT_TRUE;
}

int splt_pl_split(splt_state *state, const char *output_fname,
		double begin_point, double end_point, int *error, int save_end_point) {
	*error = SPLT_PLUGIN_ERROR_UNSUPPORTED_FEATURE;
	return end_point;
}
