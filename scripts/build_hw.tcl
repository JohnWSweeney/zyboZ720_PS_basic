# Recreate project from script
source [file normalize "hw/scripts/create_project.tcl"]

# If you have a BD, (re)build it quietly
if {[llength [get_bd_designs -quiet]] > 0} {
  validate_bd_design
  save_bd_design
}

# Synthesis not required for PS-only XSA, but run to be safe if any HDL exists
if {[llength [get_files -quiet -filter {FILE_TYPE == "VHDL" || FILE_TYPE == "Verilog"}]] > 0} {
  launch_runs synth_1 -jobs 4
  wait_on_run synth_1
}

# Export hardware platform (no bit)
file mkdir out
write_hw_platform -fixed -force -include_bit true out/ps_only.xsa
