#!/bin/bash
# Save this as: 02_ToolChain/MakeFiles/log_wrapper.sh

LOG_FILE="$1"
shift

# Execute command and capture output
"$@" 2>&1 | tee -a "$LOG_FILE"
exit ${PIPESTATUS[0]}
