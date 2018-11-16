# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License.

# Enable pending breakpoints
set breakpoint pending on

# Set a breakpoint in main (host)
b main
commands 1
    printf "** Hit breakpoint in main"
    printf "** enclave = %s\n", argv[1]
    continue
end

# Set a breakpoint in enc.c (enclave)
# This is a pending break point.
b enc.c:10
commands 2
    printf "** Hit breakpoint in enclave\n"

    # Test ability to introspect parameters
    printf "** a = %d, b = %d\n", a, b

    # Test values 
    if a != 5
        printf "** Error: a != 5\n"
        quit 1
    end

    # Test values 
    if b != 6
        printf "** Error: b != 6\n"
        quit 1
    end
    continue 
end


b enc.c:12
commands 3
    printf "** c = %d\n", c
    set variable c = 100
    continue
end

b enc.c:13
commands 4
    printf "** c = %d\n", c

    # Call a function defined within the enclave
    call square(c)

    set variable c = $1

    continue
end

# Run the program
run

# Check if program aborted or returned non zero.
if $_isvoid($_exitcode) || #_exitcode
    printf "** Test aborted\n"
    quit 1
end
