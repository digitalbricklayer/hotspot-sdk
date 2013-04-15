#pragma once

class IHint
{
public:
	virtual ~IHint() { }

	// Return the Type ID for the hint
	virtual int GetTypeId(void) const = 0;

	// All type ids for all subjects. All values should be unique
	typedef enum
	{
		data_point_unit_change = 1,
		probe_poll_begin,
		probe_poll_end,
		probe_name_change,
		probe_enable_change,
		probe_measuring_change,
		probe_type_change,
		probe_twenty_four_hour_high_change,
		probe_twenty_four_hour_low_change,
		sensor_poll_begin,
		sensor_poll_end,
		sensor_name_change,
		sensor_enable_change,
		sensor_probe_add,
		hotspot_server_poll_begin,
		hotspot_server_poll_end,
		hotspot_server_sensor_add,
		hotspot_server_sensor_remove,
		hotspot_server_temperature_unit_change,
		hotspot_server_shutdown
	} TypeId;

protected:
	IHint() { }

};

class CHint : public IHint
{
public:
	CHint(int Hint): m_Hint(Hint) { }
	~CHint(void) { }

	virtual int GetTypeId(void) const { return m_Hint; }

private:
	// The hint to be used
	int m_Hint;

};
