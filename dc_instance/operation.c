#include "data/scripts/dc_instance/config.h"

// Which instance is in use?
int dc_instance_get(char base_id)
{
	void result = getlocalvar(base_id);

	if (!result)
	{
		result = DC_INSTANCE_DEFAULT_INSTANCE;
	}

	return result;
}

void dc_instance_set(char base_id, int value)
{
	if (value == DC_INSTANCE_DEFAULT_INSTANCE)
	{
		value = NULL();
	}

	setlocalvar(DC_FIDELITY_VAR_KEY_INSTANCE, value);
}

// Caskey, Damon V.
// 2018-11-22
//
// Clears the current instance, effectively resetting
// all values to their defaults.
void dc_instance_reset(char base_id)
{
	int instance;

	// Get instance.
	instance = dc_instance_get(base_id);

	// Destroy all instance variables.
	dc_instance_free();

	// If the instance ID isn't default, then restore 
	// it to memory. Either way we now have a clean
	// copy of the current instance.
	if (instance != DC_INSTANCE_DEFAULT_INSTANCE)
	{
		dc_instance_set(base_id, instance);
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Destroy the current instance by deleting all
// library variables.
void dc_instance_free(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_fidelity_get_instance(base_id);

	// Loop from 0 to end count of library variables.
	for (i = 0; i < the_end; i++)
	{
		// Concatenate the variable ID.
		id = instance + base_id + i;

		// Delete variable.
		setlocalvar(id, NULL());
	}
}

// Caskey, Damon V.
// 2018-11-22
//
// Send all library variables to log for debugging.
void dc_instance_dump(char base_id, int the_end)
{
	int instance;
	int i;
	char id;

	// Get instance.
	instance = dc_fidelity_get_instance(base_id);

	// Log base name and instance.
	log("\n\n " + base_id + " dump:");
	log("\n\t " + "Instance: " + instance);

	// Loop from 0 to end count of instance variables.
	for (i = 0; i < the_end; i++)
	{
		// Concatenate the variable ID.
		id = instance + base_id + i;

		// Log ID.
		log("\n\t " + id + ": ");

		// Log value.
		log(getlocalvar(id));
	}

	// Log end point.
	log("\n End Dump.\n");
}

