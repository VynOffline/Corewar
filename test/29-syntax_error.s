.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r0, %:live, %1
		and r1, d, r1

live:	live %1
		zjmp %:live