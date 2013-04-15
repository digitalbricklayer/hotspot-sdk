' Write sensor values to the console

If WScript.Arguments.Count = 1 Then
 SensorIpAddress = WScript.Arguments.Item(0)
Else
 Wscript.Echo "Usage: ReadStats.vbs SensorIP"
 Wscript.Quit
End If

Dim Device
Set Device = CreateObject("SensatronicsSDK.SensatronicsModelE")
Device.IpAddress = sensorIpAddress
Device.Poll
for each Probe in Device.Probes
	Wscript.Echo "Probe number: " & Probe.Number & " Value: " & Probe.MostRecentDataPoint.Value & " Unit: " & Probe.MostRecentDataPoint.Unit
next
